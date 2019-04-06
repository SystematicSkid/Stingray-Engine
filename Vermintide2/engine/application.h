#pragma once

class ApplicationOptions
{
public:
	char pad_0000[560]; //0x0000
	char* _source_platform; //0x0230
	char pad_0238[10]; //0x0238
	bool _is_dedicated_server; //0x0242
}; //Size: 0x0242

class Application
{
public:
	char pad_0000[176]; //0x0000
	class ApplicationOptions* _options; //0x00B0
	char pad_00B8[72]; //0x00B8
	class RenderInterface* _render; //0x0100
	char pad_0108[396]; //0x0108
	float time_since_launch; //0x0294
	char pad_0298[16]; //0x0298
	Array<World*> _worlds; //0x02A8

	World* get_main_world()
	{
		return _worlds.Get(3);
	}

	void apply_user_settings()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("4C 8B DC 41 57 48 81 EC ? ? ? ? 48 8B 81 ? ? ? ?", "Vermintide2.exe"));
		function(this);
	}

	bool autoload()
	{
		using type = bool(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 33 DB 84 C0 0F 85 ? ? ? ?", "Vermintide2.exe") + 1);
		return function(this);
	}

	static std::string build_identifier()
	{
		return "8462f992ef28";
	}

	static std::string product_version()
	{
		return "Developer Build (1.3.0.0)";
	}

	void setup_renderer()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 33 C9 E8 ? ? ? ? 41 B9 ? ? ? ? 4C 8D 05 ? ? ? ?", "Vermintide2.exe") + 1);
		function(this);
	}

	void setup_input()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("40 53 48 83 EC 50 48 8B 41 40", "Vermintide2.exe"));
		function(this);
	}

	void config_renderer()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("40 55 53 56 57 41 57 48 8B EC", "Vermintide2.exe"));
		function(this);
	}

	void setup_physics()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(dwImageBase + 0x2C120); // 48 89 4C 24 ? 55 53 56 57 41 56 41 57 48 8B EC
		function(this);
	}
	
	void setup_boot_packages()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("40 53 56 48 83 EC 48", "Vermintide2.exe"));
		function(this);
	}
	
	void setup_physics_properties()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("41 56 48 83 EC 30 48 89 5C 24 ? 4C 8B F1 48 89 6C 24 ? 48 89 74 24 ?", "Vermintide2.exe"));
		function(this);
	}
	
	void setup_network()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(dwImageBase + 0x2CF70); // 48 89 6C 24 ? 56 48 83 EC 30 48 8B 41 40
		function(this);
	}
	
	void setup_entities()
	{
		using type = void(__thiscall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 30 48 8B F9 48 8D 54 24 ?", "Vermintide2.exe"));
		function(this);
	}

	void release_world(World* world)
	{
		using type = void(__thiscall*)(Application*, World*); static type function = reinterpret_cast<type>(Memory::SigScan("48 89 74 24 ? 57 48 83 EC 20 48 89 5C 24 ? 48 8B FA", "Vermintide2.exe"));
		function(this, world);
	}

	bool rendering_enabled()
	{
		RenderInterface* pRender = this->_render;
		return *reinterpret_cast<bool*>(pRender + 0x2BF);
	}

	void set_rendering_enabled(bool b)
	{
		RenderInterface* pRender = this->_render;
		*reinterpret_cast<bool*>(pRender + 0x2BF) = b;
	}

	bool update()
	{
		using type = bool(__fastcall*)(Application*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 84 C0 75 F4", "Vermintide2.exe") + 1);
		return function(this);
	}

}; //Size: 0x02A8