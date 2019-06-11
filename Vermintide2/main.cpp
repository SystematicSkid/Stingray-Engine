#include "stingray.h"

DWORD64 dwImageSize = NULL;
DWORD64 dwImageBase = NULL;

using luaL_loadstring_t = int(__fastcall*)(lua_State* L, const char* s);
luaL_loadstring_t env_loadstring;
using luaL_pcall_t = int(__fastcall*)(lua_State* L, int nargs, int nresults, int errfunc);
luaL_pcall_t env_pcall;


/// <summary>
/// Sends a lua command to the state, prints results.
/// </summary>
/// <param name="L">The lua state.</param>
/// <param name="s">The command.</param>
/// <returns></returns>
int command(lua_State* L, const char* s)
{
	HMODULE lua51 = GetModuleHandleA("lua51.dll");
	env_loadstring = reinterpret_cast<luaL_loadstring_t>(GetProcAddress(lua51, "luaL_loadstring"));
	env_pcall = reinterpret_cast<luaL_pcall_t>(GetProcAddress(lua51, "lua_pcall"));

	printf("%i\n%i\n", env_loadstring(L, s), env_pcall(L, 0, -1, 0));

	return 0;
}

void __RPC_CALLEE __RPC_CALLEE Init()
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

	int ret = command(interfaces.application->get_main_world()->_script_environment->_state, "print('test')");
	printf("Ret: %i\n", ret);

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