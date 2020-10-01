//------------------------------------------------------------------------------
//
//  SimConnect	Throttle Control sample
// 
//	Description:
//				Press A to increase the throttle
//				Press Z to decrease the throttle
//------------------------------------------------------------------------------

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include <iostream>
#include "SimConnect.h"
#include "SlimConnect.h"

/*
static enum GROUP_ID {
	GROUP_KEYS,
};
static enum INPUT_ID {
	INPUT_KEYS,
};

static enum EVENT_ID {
	EVENT_SIM_START,
	EVENT_A,
	EVENT_Z
};

static enum DATA_DEFINE_ID {
	DEFINITION_THROTTLE,
};

static enum DATA_REQUEST_ID {
	REQUEST_THROTTLE,
};

struct structStoryMode
{
	double throttlePercent;
};

structStoryMode		tc;

void CALLBACK MyDispatchProcTC(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
	HRESULT hr;

	switch (pData->dwID)
	{
	case SIMCONNECT_RECV_ID_SIMOBJECT_DATA:
	{
		SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;

		switch (pObjData->dwRequestID)
		{
		case REQUEST_THROTTLE:
		{
			// Read and set the initial throttle control value
			structStoryMode* pS = (structStoryMode*)&pObjData->dwData;

			tc.throttlePercent = pS->throttlePercent;

			printf("\nREQUEST_USERID received, throttle = %2.1f", pS->throttlePercent);

			// Now turn the input events on
			hr = SimConnect_SetInputGroupState(slimConnect.hSimConnect, INPUT_KEYS, SIMCONNECT_STATE_ON);
		}

		default:
			break;
		}
		break;
	}

	case SIMCONNECT_RECV_ID_EVENT:
	{
		SIMCONNECT_RECV_EVENT* evt = (SIMCONNECT_RECV_EVENT*)pData;

		printf("%d", evt);

		if (evt->uEventID == slimConnect.getId("SimStart"))
		{
			// Send this request to get the user aircraft id
			hr = SimConnect_RequestDataOnSimObject(slimConnect.hSimConnect, REQUEST_THROTTLE, DEFINITION_THROTTLE, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_ONCE);
			hr = SimConnect_RequestDataOnSimObject(slimConnect.hSimConnect, REQUEST_THROTTLE, DEFINITION_THROTTLE, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_ONCE);
		}
		else if (evt->uEventID == EVENT_A)
		{
			// Increase the throttle
			if (tc.throttlePercent <= 95.0f)
				tc.throttlePercent += 5.0f;

			hr = SimConnect_SetDataOnSimObject(slimConnect.hSimConnect, DEFINITION_THROTTLE, SIMCONNECT_OBJECT_ID_USER, 0, 0, sizeof(tc), &tc);
		}
		else if (evt->uEventID == EVENT_Z)
		{
			// Decrease the throttle
			if (tc.throttlePercent >= 5.0f)
				tc.throttlePercent -= 5.0f;

			hr = SimConnect_SetDataOnSimObject(slimConnect.hSimConnect, DEFINITION_THROTTLE, SIMCONNECT_OBJECT_ID_USER, 0, 0, sizeof(tc), &tc);
		}
	}

	default:
		printf("\nReceived:%d", pData->dwID);
		break;
	}
}
*/

void testStoryMode()
{
	SlimConnect& slimConnect = SlimConnect::instance();

	slimConnect.subscribeToSystemEvent("SimStart", []() { std::cout << "Sim started!\n" ; });
	slimConnect.createKeyInputEvent("PressedZ", "z", []() { std::cout << "z was pressed!\n"; });

	while (!slimConnect.shouldQuit())
	{
		slimConnect.readEvents();
		Sleep(1);
	}

	/*
	HRESULT hr;

	printf("\nConnected to Flight Simulator!");

	// Set up a data definition for the throttle control
	hr = SimConnect_AddToDataDefinition(slimConnect.hSimConnect, DEFINITION_THROTTLE, "GENERAL ENG THROTTLE LEVER POSITION:1", "percent");

	// Request a simulation started event
	slimConnect.subscribeToSystemEvent("SimStart");

	// Create two private key events to control the throttle
	hr = SimConnect_MapClientEventToSimEvent(slimConnect.hSimConnect, EVENT_A);
	hr = SimConnect_MapClientEventToSimEvent(slimConnect.hSimConnect, EVENT_Z);

	// Link the events to some keyboard keys
	hr = SimConnect_MapInputEventToClientEvent(slimConnect.hSimConnect, INPUT_KEYS, "a", EVENT_A);
	hr = SimConnect_MapInputEventToClientEvent(slimConnect.hSimConnect, INPUT_KEYS, "z", EVENT_Z);

	// Ensure the input events are off until the sim is up and running
	hr = SimConnect_SetInputGroupState(slimConnect.hSimConnect, INPUT_KEYS, SIMCONNECT_STATE_OFF);

	// Sign up for notifications
	hr = SimConnect_AddClientEventToNotificationGroup(slimConnect.hSimConnect, GROUP_KEYS, EVENT_A);
	hr = SimConnect_AddClientEventToNotificationGroup(slimConnect.hSimConnect, GROUP_KEYS, EVENT_Z);

	hr = SimConnect_RequestDataOnSimObject(slimConnect.hSimConnect, REQUEST_THROTTLE, DEFINITION_THROTTLE, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_ONCE);
	hr = SimConnect_RequestDataOnSimObject(slimConnect.hSimConnect, REQUEST_THROTTLE, DEFINITION_THROTTLE, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_ONCE);

	printf("\nPlease launch a flight");

	while (!slimConnect.shouldQuit())
	{
		SimConnect_CallDispatch(slimConnect.hSimConnect, MyDispatchProcTC, NULL);
		Sleep(1);
	}

	hr = SimConnect_Close(slimConnect.hSimConnect);
	*/
}

int __cdecl _tmain(int argc, _TCHAR* argv[])
{
	testStoryMode();

	return 0;
}
