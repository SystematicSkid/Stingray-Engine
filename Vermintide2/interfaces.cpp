#include "stingray.h"

bool Interfaces::Init()
{
	network = *reinterpret_cast<Network**>(dwImageBase + 0x54C3F8); // 48 8B 1D ? ? ? ? 48 8B 4B 40
	if (!network)
		return false;
	application = *reinterpret_cast<Application**>(dwImageBase + 0x965CD8); // 4C 8B F1 48 8B 05 ? ? ? ?
	if (!application)
		return false;

	return true;
}

Interfaces interfaces;