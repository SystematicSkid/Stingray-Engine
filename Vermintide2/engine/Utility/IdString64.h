#pragma once

class IdString64
{
public:
	int _id;

	IdString64()
	{
		_id = 0;
	}

	static unsigned __int64 generate(IdString64 *result, int length, const char *s)
	{
		using type = unsigned __int64(__fastcall*)(IdString64*, int, const char*); static type function = reinterpret_cast<type>(Memory::SigScan("E8 ? ? ? ? 8B 57 10", "Vermintide2.exe") + 1);
		return function(result, length, s);
	}
};