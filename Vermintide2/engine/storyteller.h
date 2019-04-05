#pragma once

class Storyteller
{
public:

	void stop(int id)
	{
		return (*(void(__fastcall **)(Storyteller*, int))(*(uintptr_t*)this + 16))(this, id);
	}

	float time(int id)
	{
		return (*(float(__fastcall **)(Storyteller*, int))(*(uintptr_t*)this + 32))(this, id);
	}

	void set_time(int id, float f)
	{
		return (*(void(__fastcall **)(Storyteller*, int,float))(*(uintptr_t*)this + 40))(this, id, f);
	}

	void set_speed(int id, float f)
	{
		return (*(void(__fastcall **)(Storyteller*, int, float))(*(uintptr_t*)this + 48))(this, id, f);
	}

	bool is_playing(int id)
	{
		return (*(bool(__fastcall **)(Storyteller*, int))(*(uintptr_t*)this + 64))(this, id);
	}

	float length(int id)
	{
		return (*(float(__fastcall **)(Storyteller*, int))(*(uintptr_t*)this + 88))(this, id);
	}
	
};