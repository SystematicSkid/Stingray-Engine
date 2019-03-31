#pragma once

class Window
{
public:
	char pad_0000[4]; //0x0000
	int32_t _width; //0x0004
	int32_t _height; //0x0008
}; //Size: 0x0008

class RenderInterface
{
public:
	char pad_0000[56]; //0x0000
	class Application* _application; //0x0038
	char pad_0040[16]; //0x0040
	class RenderDevice* _device; //0x0050
	char pad_0058[188]; //0x0058
	bool _enable_render; //0x0114
}; //Size: 0x0114