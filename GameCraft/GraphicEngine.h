#pragma once
#include <glc2d.h>	

class GraphicEngine
{
public:
	int Init();
	void Destroy();

	int Run();

	static int Update();
	static int Render();


};

