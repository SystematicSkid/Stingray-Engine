#include "stingray.h"

DWORD64 dwImageSize = NULL;
DWORD64 dwImageBase = NULL;

void Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	if (!interfaces.Init())
		MessageBoxA(NULL, "Interfaces: Failed to init!", NULL, NULL);

	printf("Application: 0x%p\n", interfaces.application);
	printf("Network: 0x%p\n", interfaces.network);
	printf("World: 0x%p\n", interfaces.application->get_main_world());

	while(true)
	{
		interfaces.application->setup_network();
	}

}

DWORD __stdcall DllMain( _In_ void* _DllHandle, _In_ unsigned long _Reason, _In_opt_ void* _Reserved )
{
	if(_Reason == DLL_PROCESS_ATTACH)
	{
		dwImageBase = reinterpret_cast<DWORD64>(Memory::GetModuleBaseAddress("Vermintide2.exe"));

		PIMAGE_NT_HEADERS nthdr = Memory::GetNTHeader(Memory::GetModuleBaseAddress("Vermintide2.exe"));
		if (nthdr == nullptr)
			return false;

		dwImageSize = static_cast<DWORD64>(nthdr->OptionalHeader.SizeOfImage);

		CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Init), NULL, NULL, NULL);
		return 1;
	}
	return 0;
}