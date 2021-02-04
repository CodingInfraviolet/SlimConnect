//------------------------------------------------------------------------------
//
//  SimConnect	Throttle Control sample
// 
//	Description:
//				Press A to increase the throttle
//				Press Z to decrease the throttle
//------------------------------------------------------------------------------

#include <tchar.h>
#include <iostream>
#include "SlimConnect.h"

void testStoryMode()
{
	SlimConnect& slimConnect = SlimConnect::instance();

	slimConnect.subscribeToSystemEvent("SimStart", [](const SimArguments*) { std::cout << "Sim started!\n" ; });
	slimConnect.createKeyInputEvent("PressedZ", "z", [](const SimArguments*) { std::cout << "z was pressed!\n"; });
	slimConnect.subscribeToObjectData("PLANE ALTITUDE", Unit(Unit::Type::Feet), [](const SimArguments* arguments) { 
		std::cout << "Got data! " << *((double*)&arguments->objectData->dwData) << "\n";
	});

	while (!slimConnect.shouldQuit())
	{
		slimConnect.readEvents();
		Sleep(1);
	}
}

int __cdecl _tmain(int argc, _TCHAR* argv[])
{
	testStoryMode();

	return 0;
}
