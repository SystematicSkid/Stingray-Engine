#pragma once

class Storyteller
{
public:

	/// <summary>
	/// Stops the Storyteller.
	/// </summary>
	/// <param name="id">The identifier.</param>
	void stop(int id)
	{
		return (*reinterpret_cast<void(__fastcall **)(Storyteller*, int)>(*reinterpret_cast<uintptr_t*>(this) + 16))(this, id);
	}

	/// <summary>
	/// Gets the time of the storyteller id.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns></returns>
	float time(int id)
	{
		return (*reinterpret_cast<float(__fastcall **)(Storyteller*, int)>(*reinterpret_cast<uintptr_t*>(this) + 32))(this, id);
	}

	/// <summary>
	/// Sets the time.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <param name="f">The f.</param>
	void set_time(int id, float f)
	{
		return (*reinterpret_cast<void(__fastcall **)(Storyteller*, int, float)>(*reinterpret_cast<uintptr_t*>(this) + 40))(this, id, f);
	}

	/// <summary>
	/// Sets the speed.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <param name="f">The f.</param>
	void set_speed(int id, float f)
	{
		return (*reinterpret_cast<void(__fastcall **)(Storyteller*, int, float)>(*reinterpret_cast<uintptr_t*>(this) + 48))(this, id, f);
	}

	/// <summary>
	/// Determines whether the specified identifier is playing.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns>
	///   <c>true</c> if the specified identifier is playing; otherwise, <c>false</c>.
	/// </returns>
	bool is_playing(int id)
	{
		return (*reinterpret_cast<bool(__fastcall **)(Storyteller*, int)>(*reinterpret_cast<uintptr_t*>(this) + 64))(this, id);
	}

	/// <summary>
	/// Gets the length the specified identifier.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns></returns>
	float length(int id)
	{
		return (*reinterpret_cast<float(__fastcall **)(Storyteller*, int)>(*reinterpret_cast<uintptr_t*>(this) + 88))(this, id);
	}
	
};