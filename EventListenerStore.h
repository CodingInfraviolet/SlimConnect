#pragma once
#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include "SimConnect.h"
#include "EventHandler.h"
#include "SimArguments.h"

template <class FN>
class EventListenerStore
{
private:
	std::map<std::string, EventHandler<FN>> events;
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
	SIMCONNECT_CLIENT_EVENT_ID add(const std::string& eventName, const std::function<FN>& callback)
	{
		ensureResourceIsFree(eventName);
		SIMCONNECT_CLIENT_EVENT_ID id = events.size();
		events[eventName].id = id;
		events[eventName].add(callback);
		eventIdToName[id] = eventName;
		return id;
	}

	void call(const std::string& eventName, const SimArguments* data) const
	{
		events.find(eventName)->second.call(data);
	}

	void call(const SIMCONNECT_CLIENT_EVENT_ID eventId, const SimArguments* data) const
	{
		call(eventNameFromId(eventId), data);
	}

	SIMCONNECT_CLIENT_EVENT_ID getId(const std::string& eventName) const
	{
		return events.find(eventName)->second.id;
	}
};