#pragma once

namespace PluginInterface
{
	namespace Internal
	{
		class PluginInterfaceInternal
		{
		public:
			/// <summary>
			/// Adds a module function to the API.
			/// </summary>
			/// <param name="module">The module.</param>
			/// <param name="name">The name.</param>
			/// <param name="f">The function.</param>
			static void api_add_module_function(const char *module, const char *name, int(__fastcall *f)(lua_State*))
			{
				using type = void(__fastcall*)(const char*, const char*, int(__fastcall *)(lua_State*)); static type function = reinterpret_cast<type>(Memory::SigScan("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B 35 ? ? ? ? 48 8B DA 48 8B D1 49 8B F8 48 8B 0E E8 ? ? ? ? 48 8B 0E 48 8B D3 FF 15 ? ? ? ? 48 8B 0E 45 33 C0", "Vermintide2.exe"));
				function(module,name, f);
			}

			/// <summary>
			/// Sets a bool variable in an API module.
			/// </summary>
			/// <param name="module">The module.</param>
			/// <param name="key">The key.</param>
			/// <param name="val">The value.</param>
			static void api_set_module_bool(const char *module, const char *key, int val)
			{
				using type = void(__fastcall*)(const char*, const char*, int); static type function = reinterpret_cast<type>(Memory::SigScan("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B 35 ? ? ? ? 48 8B DA 48 8B D1 49 8B F8 48 8B 0E E8 ? ? ? ? 48 8B 0E 48 8B D3 FF 15 ? ? ? ? 48 8B 0E 48 8B D7", "Vermintide2.exe"));
				function(module, key, val);
			}
		};
	}
}