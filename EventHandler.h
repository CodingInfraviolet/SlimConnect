#pragma once
#include <vector>
#include <windows.h>
#include <functional>
#include "SimConnect.h"
#include "SimArguments.h"

template <class FN>
class EventHandler
{
private:
	std::vector<std::function<FN>> callbacks;
public:
	SIMCONNECT_CLIENT_EVENT_ID id;
	EventHandler() {}

	void add(const std::function<FN>& callback)
	{
		callbacks.push_back(callback);
	}

	void call(const SimArguments* arguments) const
	{
		for (const auto& callback : callbacks)
		{
			callback(arguments);
		}
	}
};
