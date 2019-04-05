#pragma once

class Interfaces
{
public:
	Application* application;
	Network* network;

	bool Init();
};

extern Interfaces interfaces;