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

extern DWORD64 dwImageSize;
extern DWORD64 dwImageBase;

// util
#include "memory.h"
#include "Engine/vector.h"

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



#include "lua/lua.hpp"
#pragma comment(lib, "Lua51.lib")


#include "Engine/Utility/IdString64.h"

#include "Engine/Physics/actor.h"

#include "Engine/unit.h"
#include "Engine/luaenvironment.h"
#include "Engine/level.h"
#include "Engine/shadingenvironment.h"
#include "Engine/storyteller.h"
#include "Engine/world.h"
#include "Engine/renderinterface.h"
#include "Engine/application.h"

#include "Engine/PluginInterface/internal.h"

#include "Engine/Network/unitsynchronizer.h"
#include "Engine/Network/gamesession.h"
#include "Engine/Network/network.h"


// core
#include "interfaces.h"