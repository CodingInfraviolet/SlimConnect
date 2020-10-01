#pragma once
#include <stdexcept>
#include <windows.h>
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include "SimConnect.h"

class EventHandler
{
public:
	SIMCONNECT_CLIENT_EVENT_ID id;
	std::function<void()> callback;
	EventHandler() {}
	EventHandler(SIMCONNECT_CLIENT_EVENT_ID id, const std::function<void()>& callback)
		: id(id), callback(callback) {}
};

class EventIdStore
{
private:
	std::map<std::string, SIMCONNECT_CLIENT_EVENT_ID> events;
	std::map<SIMCONNECT_CLIENT_EVENT_ID, std::string> eventIdToName;

	void ensureResourceIsFree(std::string resourceName) const
	{
		if (events.count(resourceName) != 0)
		{
			throw std::runtime_error(std::string("resource was already assigned: ") + resourceName);
		}
	}

	std::string eventNameFromId(const SIMCONNECT_CLIENT_EVENT_ID eventId) const
	{
		return eventIdToName.find(eventId)->second;
	}

public:
	SIMCONNECT_CLIENT_EVENT_ID add(const std::string& eventName)
	{
		ensureResourceIsFree(eventName);
		SIMCONNECT_CLIENT_EVENT_ID id = events.size();
		events[eventName] = id;
		eventIdToName[id] = eventName;
		return id;
	}

	SIMCONNECT_CLIENT_EVENT_ID getId(const std::string& eventName) const
	{
		return events.find(eventName)->second;
	}
};

class EventListenerStore
{
private:
	std::map<std::string, EventHandler> events;
	std::map<SIMCONNECT_CLIENT_EVENT_ID, std::string> eventIdToName;

	void ensureResourceIsFree(std::string resourceName) const
	{
		if (events.count(resourceName) != 0)
		{
			throw std::runtime_error(std::string("resource was already assigned: ") + resourceName);
		}
	}

	std::string eventNameFromId(const SIMCONNECT_CLIENT_EVENT_ID eventId) const
	{
		return eventIdToName.find(eventId)->second;
	}

public:
	SIMCONNECT_CLIENT_EVENT_ID add(const std::string& eventName, const std::function<void()>& callback)
	{
		ensureResourceIsFree(eventName);
		SIMCONNECT_CLIENT_EVENT_ID id = events.size();
		events[eventName] = EventHandler(id, callback);
		eventIdToName[id] = eventName;
		return id;
	}

	void call(const std::string& eventName) const
	{
		events.find(eventName)->second.callback();
	}

	void call(const SIMCONNECT_CLIENT_EVENT_ID eventId) const
	{
		call(eventNameFromId(eventId));
	}

	SIMCONNECT_CLIENT_EVENT_ID getId(const std::string& eventName) const
	{
		return events.find(eventName)->second.id;
	}
};

class SlimConnect
{
private:
	static SlimConnect* self;

	HANDLE  hSimConnect = nullptr;
	HRESULT hr = 0;
	bool quit = false;
	EventListenerStore eventListenerStore;

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
			//SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;

			// pObjData->dwRequestID
			// Got requested data
			break;
		}
		case SIMCONNECT_RECV_ID_EVENT:
		{
			SIMCONNECT_RECV_EVENT* event = (SIMCONNECT_RECV_EVENT*)pData;
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
		if (!SUCCEEDED(SimConnect_Open(&hSimConnect, "Throttle Control", NULL, 0, 0, 0)))
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
