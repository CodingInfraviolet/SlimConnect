#pragma once
#include <vector>
#include <windows.h>
#include <functional>
#include "SimConnect.h"

template <class FN>
class EventHandler
{
private:
	std::vector<std::function<FN>> callbacks;
public:
	SIMCONNECT_CLIENT_EVENT_ID id;
	EventHandler() {}

	void add(const std::function<void()>& callback)
	{
		callbacks.push_back(callback);
	}

	void call() const
	{
		for (const auto& callback : callbacks)
		{
			callback();
		}
	}
};
