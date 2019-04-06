#pragma once
class World
{
public:
	char pad_0000[296]; //0x0000
	class LuaEnvironment* _script_environment; //0x0128
	char pad_0130[8]; //0x0130
	class ResourceManager* _resource_manager; //0x0138
	char pad_0140[16]; //0x0140
	class Storyteller* _storyteller; //0x0150
	char pad_0158[656]; //0x0158
	Array<Level*> _levels; //0x03E8
	Array<Unit*> _units; //0x0400
	char pad_0418[880]; //0x0418
	float _delta_time; //0x0788
	float _time; //0x078C
	float _render_delta_time; //0x0790
	float _render_time; //0x0794
	char pad_0798[8]; //0x0798
	class PhysicsWorld* _physics_world; //0x07A0
	int32_t _update_count; //0x07A8

	ShadingEnvironment* create_shading_environment(IdString64 *name)
	{
		using type = ShadingEnvironment*(__thiscall*)(World*, IdString64*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 48 83 C4 50 41 5F C3", "Vermintide2.exe"));
		return function(this, name);
	}
}; //Size: 0x7A8