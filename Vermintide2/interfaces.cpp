#include "stingray.h"

bool Interfaces::Init()
{
	network = *reinterpret_cast<Network**>(Memory::SigScan("48 8B 1D ? ? ? ? 48 8B 4B 40", "Vermintide2.exe"));
	if (!network)
		return false;

	application = *reinterpret_cast<Application**>(0x7FF6F7766CE0); // Static for testing
	if (!application)
		return false;

	return true;
}

Interfaces interfaces;