#pragma once
class Unit
{
public:
	char pad_0000[16]; //0x0000
	class World* pWorld; //0x0010
	char pad_0018[8]; //0x0018
	class ResourceManager* pResourceManager; //0x0020
	class Resource* pResource; //0x0028
	class MaterialManager* pMaterialManager; //0x0030
	class Resource* pMaterialResource; //0x0038
	char pad_0040[152]; //0x0040
	Array<void*> _meshes; //0x00D8 // not reversed yet
	char pad_00F0[332]; //0x00F0
	int32_t _moving_until; //0x023C
	char pad_0240[888]; //0x0240
}; //Size: 0x05B8