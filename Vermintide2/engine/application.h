#pragma once

class ApplicationOptions
{
public:
	char pad_0000[560]; //0x0000
	char* _source_platform; //0x0230
	char pad_0238[10]; //0x0238
	bool _is_dedicated_server; //0x0242
}; //Size: 0x0242

class Application
{
public:
	char pad_0000[176]; //0x0000
	class ApplicationOptions* _options; //0x00B0
	char pad_00B8[72]; //0x00B8
	class RenderInterface* _render; //0x0100
	char pad_0108[396]; //0x0108
	float time_since_launch; //0x0294
	char pad_0298[16]; //0x0298
	Array<World*> _worlds; //0x02A8

	World* GetMainWorld()
	{
		return _worlds.Get(3);
	}
}; //Size: 0x02A8