#pragma once

class UnitSynchronizer
{
public:
	/// <summary>
	/// Sets the world.
	/// </summary>
	/// <param name="world">The world.</param>
	void set_world(World* world)
	{
		return (*reinterpret_cast<void(__fastcall **)(UnitSynchronizer*, World*)>(*reinterpret_cast<uintptr_t*>(this) + 32))(this, world);
	}

	/// <summary>
	/// Destroys the unit.
	/// </summary>
	/// <param name="unit">The unit.</param>
	void destroy_unit(Unit* unit)
	{
		return (*reinterpret_cast<void(__fastcall **)(UnitSynchronizer*, Unit*)>(*reinterpret_cast<uintptr_t*>(this) + 48))(this, unit);
	}

	/// <summary>
	/// Converts the object ID to a unit.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns></returns>
	Unit* game_object_id_to_unit(int id)
	{
		return (*reinterpret_cast<Unit*(__fastcall **)(UnitSynchronizer*, int)>(*reinterpret_cast<uintptr_t*>(this) + 56))(this, id);
	}

	/// <summary>
	/// Converts a unit to an object ID.
	/// </summary>
	/// <param name="unit">The unit.</param>
	/// <returns></returns>
	int unit_to_game_object_id(Unit* unit)
	{
		return (*reinterpret_cast<int(__fastcall **)(UnitSynchronizer*, Unit*)>(*reinterpret_cast<uintptr_t*>(this) + 64))(this, unit);
	}
};