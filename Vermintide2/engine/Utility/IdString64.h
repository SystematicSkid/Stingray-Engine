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
		using type = unsigned __int64(__fastcall*)(IdString64*, int, const char*); static type function = reinterpret_cast<type>(dwImageBase + 0x2C40D0); // E8 ? ? ? ? 8B 57 10
		return function(result, length, s);
	}

	static const char* lookup_safe(IdString64* str)
	{
		using type = const char*(__fastcall*)(IdString64*); static type function = reinterpret_cast<type>(dwImageBase + 0x2CA6F0); // E8 ? ? ? ? 48 8D 4F EC
		return function(str);
	}
};