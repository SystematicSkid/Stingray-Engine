#pragma once
// win
#include <Windows.h>
#include <winternl.h>
#include <Xinput.h>
#include <d3d11.h>
#include <comdef.h>
#include <minwindef.h>
#include <winbase.h>
#include <intrin.h>
#include <psapi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx10.lib")

// stl
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <clocale>
#include <algorithm>
#include <sstream>

#define PTR_MAX_VALUE ((PVOID)0x000F000000000000)
_forceinline bool IsValidPtr(PVOID p) { return (p >= (PVOID)0x10000) && (p < PTR_MAX_VALUE); }

// sdk
template <class T>
struct Array
{
	int32_t _size; //0x0000
	int32_t _capacity; //0x0004
	T* _data;
	void* _allocator;

	T Get(int idx)
	{
		return _data[idx];
	}
};

#include "engine/unit.h"
#include "engine/luaenvironment.h"
#include "engine/world.h"
#include "engine/renderinterface.h"
#include "engine/application.h"


// core
#include "interfaces.h"