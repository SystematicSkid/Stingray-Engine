#pragma once
#include "stingray.h"

typedef uintptr_t ptr;
typedef unsigned int uint;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

class Memory
{
public:
	static HMODULE __stdcall GetModuleBaseAddress(std::string modulename);
	static std::string HexToBytes(std::string hex);
	static ptr SigScan(const char* pattern, const char* module);
	static PIMAGE_NT_HEADERS GetNTHeader(HMODULE hmModule);
};

struct GetPatternByte
{
	GetPatternByte() : ignore(true)
	{
	}

	GetPatternByte(std::string byteString, bool ignoreThis = false) {
		data = StringToUint8(byteString);
		ignore = ignoreThis;
	}

	bool ignore;
	UINT8 data;

private:
	UINT8 StringToUint8(std::string str)
	{
		std::istringstream iss(str);

		UINT32 ret;

		if (iss >> std::hex >> ret)
		{
			return (UINT8)ret;
		}

		return 0;
	}
};

struct FindPattern
{
	static DWORD64 Find(DWORD64 dwStart, DWORD64 dwLength, std::string s) {
		std::vector<GetPatternByte> p;
		std::istringstream iss(s);
		std::string w;

		while (iss >> w)
		{
			if (w.data()[0] == '?')
			{
				p.push_back(GetPatternByte());
			}
			else if (w.length() == 2 && isxdigit(w.data()[0]) && isxdigit(w.data()[1])) { // Hex
				p.push_back(GetPatternByte(w));
			}
			else
			{
				return NULL;
			}
		}

		for (DWORD64 i = 0; i < dwLength; i++)
		{
			UINT8* lpCurrentByte = (UINT8*)(dwStart + i);

			bool found = true;

			for (size_t ps = 0; ps < p.size(); ps++)
			{
				if (p[ps].ignore == false && lpCurrentByte[ps] != p[ps].data) {
					found = false;
					break;
				}
			}

			if (found)
			{
				return (DWORD64)lpCurrentByte;
			}
		}

		return NULL;
	}
	
	static DWORD64 Find(std::string s)
	{
	return Find(static_cast<DWORD64>(dwImageBase), static_cast<DWORD64>(dwImageSize), s);
	}
};