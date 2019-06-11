#pragma once

class Actor
{
public:

	/// <summary>
	/// Determines whether PhysX collision is enabled.
	/// </summary>
	/// <returns>
	///   <c>true</c> if [is collision enabled]; otherwise, <c>false</c>.
	/// </returns>
	bool is_collision_enabled()
	{
		return *reinterpret_cast<bool*>(this + 0x90);
	}

	/// <summary>
	/// Sets if the PhysX collision is enabled.
	/// </summary>
	/// <param name="b">if set to <c>true</c> [b].</param>
	void set_collision_enabled_internal(bool b)
	{
		*reinterpret_cast<bool*>(this + 0x90) = b;
	}

	/// <summary>
	/// Determines whether this object will be updated.
	/// </summary>
	/// <returns>
	///   <c>true</c> if [is update enabled]; otherwise, <c>false</c>.
	/// </returns>
	bool is_update_enabled()
	{
		return *reinterpret_cast<bool*>(this + 0x93);
	}

	void set_update_enabled(bool b)
	{
		*reinterpret_cast<bool*>(this + 0x93) = b;
	}

	void set_collision_enabled(bool b)
	{
		using type = void(__fastcall*)(Actor*, bool); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 41 8B 4F 38 C1 E9 03", "Vermintide2.exe") + 1);
		function(this, b);
	}

	/// <summary>
	/// Determines whether gravity is enabled.
	/// </summary>
	/// <returns>
	///   <c>true</c> if [is gravity enabled]; otherwise, <c>false</c>.
	/// </returns>
	bool is_gravity_enabled()
	{
		char v3;
		bool v1 = *reinterpret_cast<bool*>((*reinterpret_cast<__int64(__fastcall **)(uintptr_t, char*)>(**(reinterpret_cast<uintptr_t **>(this) + 136) +
			96))(
			*(reinterpret_cast<uintptr_t *>(this) + 136),
			&v3));
		v1 = ~static_cast<WORD>(v1);
		return ~(v1 >> 1) & 1;
	}

	void set_gravity_enabled(bool b)
	{
		(*reinterpret_cast<void(__fastcall **)(uintptr_t, signed int, int)>(**(reinterpret_cast<uintptr_t **>(this) + 136) +
			80))(
				*(reinterpret_cast<uintptr_t *>(this) + 136), 2,
				b);
	}

	bool is_static()
	{
		uintptr_t* pResource = *reinterpret_cast<uintptr_t**>(this + 0x88);
		return (*reinterpret_cast<int*>(this + 0x8) == 7);
	}

	bool is_dynamic()
	{
		uintptr_t* pResource = *reinterpret_cast<uintptr_t**>(this + 0x88);
		return (*reinterpret_cast<int*>(this + 0x8) == 6);
	}

	float mass()
	{
		uintptr_t* pResource = *reinterpret_cast<uintptr_t**>(this + 0x88);
		return (*reinterpret_cast<float(**)(void)>(*static_cast<uintptr_t *>(pResource) + 256))();
	}

	void add_impulse(Vector v)
	{
		// Base + 0xE8040
		using type = void(__fastcall*)(Actor*, Vector*); static type function = reinterpret_cast<type>(Memory::GetModuleBaseAddress("Vermintide2.exe") + 0xE8040);
		function(this, &v);
	}
};