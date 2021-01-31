#pragma once
#include <map>
#include <stdexcept>
#include <string>
#include <windows.h>
#include "SimConnect.h"
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