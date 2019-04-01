#include "stingray.h"

bool Interfaces::Init()
{
	printf("Base: 0x%p\n", Memory::GetModuleBaseAddress("vermintide2.exe"));
	application = *(Application**)(0x7FF6F7766CE0); // Static for testing
	printf("Application: 0x%p\n", application);
	return application != nullptr;
}

Interfaces interfaces;