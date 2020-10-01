# Introduction

🚧 This project is still in early development and not ready for real use 🚧

Have you ever decided to write a plugin for Microsoft Flight Simulator, but had a quick look at the SimConnect API and decided that this was definitely not for you?

Me too!

So I decided to write SlimConnect, a more modern, simplified wrapper around SimConnect. With modern programming practices, better abstractions, and CPUs faster than 16MHz, we shouldn't have to deal with a legacy hard-to-use API if we don't want to. SlimConnect should serve as an answer to that.

## Example

```
#include <tchar.h>
#include <iostream>
#include "SlimConnect.h"

int __cdecl _tmain(int argc, _TCHAR* argv[])
{
	SlimConnect& slimConnect = SlimConnect::instance();

	slimConnect.subscribeToSystemEvent("SimStart", []() { std::cout << "Sim started!\n" ; });
	slimConnect.createKeyInputEvent("PressedZ", "z", []() { std::cout << "z was pressed!\n"; });

	while (!slimConnect.shouldQuit())
	{
		slimConnect.readEvents();
		Sleep(1);
	}

	return 0;
}

```
