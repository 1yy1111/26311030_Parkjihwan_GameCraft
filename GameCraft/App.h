#pragma once
#include "GraphicEngine.h"

class App
{
public:
	App();
	virtual ~App();

public:
	int Init();
	void Destroy();
	int Update();
	int Render();

	int Run();


protected:
	GraphicEngine m_graphicEngine;

};

extern App* g_pApp;
