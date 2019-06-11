#pragma once
class Unit
{
public:
	char pad_0000[16]; //0x0000
	class World* pWorld; //0x0010
	char pad_0018[8]; //0x0018
	class ResourceManager* pResourceManager; //0x0020
	uintptr_t* pResource; //0x0028
	class MaterialManager* pMaterialManager; //0x0030
	class Resource* pMaterialResource; //0x0038
	char pad_0040[152]; //0x0040
	Array<void*> _meshes; //0x00D8 // not reversed yet
	char pad_00F0[332]; //0x00F0
	int32_t _moving_until; //0x023C


/// <summary>
/// The debug name.
/// </summary>
/// <returns>The debug name</returns>
	const char* debug_name()
	{
		IdString64 id = *reinterpret_cast<IdString64*>(this->pResource + 0x48);
		return IdString64::lookup_safe(&id);
	}

	/// <summary>
	/// Check if unit is alive.
	/// </summary>
	/// <returns></returns>
	bool alive()
	{
		return *reinterpret_cast<bool*>(this + 0x3F9) == 0;
	}

	/// <summary>
	/// Set object to frozen.
	/// </summary>
	/// <param name="b">if set to <c>true</c> [b].</param>
	/// <returns></returns>
	int set_frozen(bool b)
	{
		*reinterpret_cast<bool*>(this + 0x3F9) = b;
		uintptr_t* world = *reinterpret_cast<uintptr_t**>(this + 0x10);
		using type = __int64(__fastcall*)(uintptr_t*, uintptr_t*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 48 8B 93 ? ? ? ? 33 FF", "Vermintide2.exe") + 1);
		return function(*reinterpret_cast<uintptr_t**>(world + 0x770), *reinterpret_cast<uintptr_t**>(this + 0x40));
	}

	/// <summary>
	/// Determines whether this instance is frozen.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is frozen; otherwise, <c>false</c>.
	/// </returns>
	bool is_frozen()
	{
		return *reinterpret_cast<bool*>(this + 0x3F9);
	}


	/// <summary>
	/// Disables the physics.
	/// </summary>
	/// <returns></returns>
	bool disable_physics()
	{
		uintptr_t* world = *reinterpret_cast<uintptr_t**>(this + 0x10);
		if (*reinterpret_cast<bool*>(world + 0x7AC)) // Check if physics are being updated
			return false;
		using type = void(__fastcall*)(Unit*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 48 8B 43 28 4C 8B BC 24 ? ? ? ?", "Vermintide2.exe") + 1);
		function(this);
		return true;
	}

	/// <summary>
	/// Enables the physics.
	/// </summary>
	/// <returns></returns>
	bool enable_physics()
	{
		uintptr_t* world = *reinterpret_cast<uintptr_t**>(this + 0x10);
		if (*reinterpret_cast<bool*>(world + 0x7AC)) // Check if physics are being updated
			return false;
		if (!*reinterpret_cast<uintptr_t*>(this + 0x138) && !*reinterpret_cast<uintptr_t*>(this + 0x170) && !*reinterpret_cast<uintptr_t*>(this + 0x1B8))
		{
			using type = void(__fastcall*)(Unit*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 49 8B 8D ? ? ? ? 48 85 C9", "Vermintide2.exe") + 1);
			function(this);
			return true;
		}
		return false;
	}

	/// <summary>
	/// Enables the proximity unit.
	/// </summary>
	void enable_proximity_unit()
	{
		uintptr_t* world = *reinterpret_cast<uintptr_t**>(this + 0x10);
		if (*reinterpret_cast<bool*>(world + 0x7AC)) // Check if physics are being updated
			return;
		if (!*reinterpret_cast<uintptr_t*>(this + 0x1E0) && !*reinterpret_cast<bool*>(this + 0x1E8))
		{
			__int64 v5 = (*reinterpret_cast<__int64(**)()>(**reinterpret_cast<uintptr_t**>(*reinterpret_cast<uintptr_t*>(this + 16) + 1952) + 392))();
			*reinterpret_cast<BYTE *>(this + 488) = 1;
		}
	}

	/// <summary>
	/// Sets the visibilty.
	/// </summary>
	/// <param name="group">The ID group.</param>
	/// <param name="state">if set to <c>true</c> [state].</param>
	void set_visibilty(IdString64 group, bool state)
	{
		using type = void(__fastcall*)(Unit*, IdString64, bool); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? EB 0B 45 85 C9", "Vermintide2.exe") + 1);
		function(this, group, state);
	}

	/// <summary>
	/// Sets the unit visibility.
	/// </summary>
	/// <param name="state">if set to <c>true</c> [state].</param>
	void set_unit_visibility(bool state)
	{
		using type = void(__fastcall*)(Unit*, bool); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? B8 ? ? ? ? 4C 8D 44 24 ?", "Vermintide2.exe") + 1);
		function(this, state);
	}

	/// <summary>
	/// Gets the 32-bit ID.
	/// </summary>
	/// <returns></returns>
	__int32 id32()
	{
		return (__int32)(signed int)(*(uintptr_t *)(this + 0x240) >> 32);
	}

	/// <summary>
	/// Gets the 64-bit ID.
	/// </summary>
	/// <returns></returns>
	int id()
	{
		return *(__int32*)(this + 0x268);
	}

}; //Size: 0x05B8