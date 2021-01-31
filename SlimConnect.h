#pragma once
#include <stdexcept>
#include <windows.h>
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <vector>
#include "SimConnect.h"
#include "EventIdStore.h"
#include "EventListenerStore.h"
#include "Unit.h"

struct ThrottleControlData
{
	double percent;
};

class SlimConnect
{
private:
	static SlimConnect* self;

	HANDLE  hSimConnect = nullptr;
	HRESULT hr = 0;
	bool quit = false;
	EventListenerStore<void()> eventListenerStore;
	EventListenerStore<void()> dataDefinitionStore;

	enum class InputGroups {
		Default,
	};

	enum class KeyGroups {
		Default,
	};

	static void CALLBACK handleEvents(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
	{
		switch (pData->dwID)
		{
		case SIMCONNECT_RECV_ID_SIMOBJECT_DATA:
		{
			SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
			self->eventListenerStore.call(pObjData->dwRequestID);
			break;
		}
		case SIMCONNECT_RECV_ID_EVENT:
		{
			SIMCONNECT_RECV_EVENT* event = (SIMCONNECT_RECV_EVENT*)pData;
			ThrottleControlData* data = (ThrottleControlData*)event->dwData;
			self->eventListenerStore.call(event->uEventID);
			break;
		}
		case SIMCONNECT_RECV_ID_QUIT:
		{
			self->quit = true;
			break;
		}
		default:
		{
			break;
		}
		}
	}

	SlimConnect()
	{
		if (!SUCCEEDED(SimConnect_Open(&hSimConnect, "SlimConnect", NULL, 0, 0, 0)))
		{
			throw std::runtime_error("Failed initialising SimConnect");
		}
	}

	SlimConnect(SlimConnect&) {};
	SlimConnect(SlimConnect&&) {};

	void registerEvent()
	{

	}

public:

	static SlimConnect& instance()
	{
		if (!self)
		{
			self = new SlimConnect();
			return *self;
		}
		else
		{
			throw std::runtime_error("Can not create multiple SlimConnect instances due to SimConnect API restrictions");
		}
	}

	virtual ~SlimConnect()
	{
		SimConnect_Close(hSimConnect);
	}

	SlimConnect& subscribeToSystemEvent(const std::string& eventName, const std::function<void()>& callback)
	{
		eventListenerStore.add(eventName, callback);
		hr = SimConnect_SubscribeToSystemEvent(hSimConnect, eventListenerStore.getId(eventName), "SimStart");
		return *this;
	}

	void subscribeToObjectData(const std::string& requestedData, const Unit unit, const std::function<void()>& callback)
	{
		int dataDefinition = dataDefinitionStore.add(requestedData, []() {});
		int requestEvent = eventListenerStore.add(requestedData, callback);
		hr = SimConnect_AddToDataDefinition(hSimConnect, dataDefinition, requestedData.c_str(), static_cast<const char*>(unit));
		hr = SimConnect_RequestDataOnSimObject(hSimConnect, requestEvent, dataDefinition, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME);
	}

	void createKeyInputEvent(const std::string& eventName, const std::string& key, const std::function<void()>& onKeyDown)
	{
		int event = eventListenerStore.add(eventName, onKeyDown);
		hr = SimConnect_MapClientEventToSimEvent(hSimConnect, event);
		hr = SimConnect_AddClientEventToNotificationGroup(hSimConnect, static_cast<int>(KeyGroups::Default), event);
		hr = SimConnect_MapInputEventToClientEvent(hSimConnect, static_cast<int>(InputGroups::Default), key.c_str(), event);
		hr = SimConnect_SetInputGroupState(hSimConnect, static_cast<int>(InputGroups::Default), SIMCONNECT_STATE_ON);
		//hr = SimConnect_SetNotificationGroupPriority(hSimConnect, static_cast<int>(KeyGroups::Default), SIMCONNECT_GROUP_PRIORITY_HIGHEST);
	}

	bool shouldQuit() const
	{
		return quit;
	}

	void readEvents()
	{
		SimConnect_CallDispatch(hSimConnect, handleEvents, NULL);
	}
};
