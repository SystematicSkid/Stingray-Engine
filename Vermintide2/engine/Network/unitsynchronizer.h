#pragma once

class UnitSynchronizer
{
public:
	void set_world(World* world)
	{
		return (*reinterpret_cast<void(__fastcall **)(UnitSynchronizer*, World*)>(*reinterpret_cast<uintptr_t*>(this) + 32))(this, world);
	}

	void destroy_unit(Unit* unit)
	{
		return (*reinterpret_cast<void(__fastcall **)(UnitSynchronizer*, Unit*)>(*reinterpret_cast<uintptr_t*>(this) + 48))(this, unit);
	}

	Unit* game_object_id_to_unit(int id)
	{
		return (*reinterpret_cast<Unit*(__fastcall **)(UnitSynchronizer*, int)>(*reinterpret_cast<uintptr_t*>(this) + 56))(this, id);
	}

	int unit_to_game_object_id(Unit* unit)
	{
		return (*reinterpret_cast<int(__fastcall **)(UnitSynchronizer*, Unit*)>(*reinterpret_cast<uintptr_t*>(this) + 64))(this, unit);
	}
};