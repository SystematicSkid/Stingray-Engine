#include "stingray.h"

void Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	if (!interfaces.Init())
		MessageBoxA(NULL, "Interfaces: Failed to init!", NULL, NULL);

}

DWORD __stdcall DllMain( _In_ void* _DllHandle, _In_ unsigned long _Reason, _In_opt_ void* _Reserved )
{
	if(_Reason == DLL_PROCESS_ATTACH)
	{
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Init, NULL, NULL, NULL);
		return 1;
	}
	return 0;
}