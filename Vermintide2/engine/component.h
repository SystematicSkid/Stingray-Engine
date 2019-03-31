#pragma once
class Component
{
public:
	char pad_0000[32]; //0x0000
	char* _name; //0x0020
	char pad_0028[16]; //0x0028
}; //Size: 0x0038