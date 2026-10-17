#if defined(_DEBUG)
	#if defined(_M_X64) // 64-bit 아키텍처
		#pragma comment(lib, "glc2d_x64_debug.lib")
	#elif defined(_M_IX86) // 32-bit 아키텍처
		#pragma comment(lib, "glc2d_win32_debug.lib")
	#endif
#else
	#if defined(_M_X64)
		#pragma comment(lib, "glc2d_x64_release.lib")
	#elif defined(_M_IX86)
		#pragma comment(lib, "glc2d_win32_release.lib")
	#endif
#endif

#include "GraphicEngine.h"
#include "App.h"

int GraphicEngine::Update()
{
	return g_pApp->Update();
}

int GraphicEngine::Render()
{
	return g_pApp->Render();
}

void GraphicEngine::SetColor(unsigned long color)
{
	g2_SetClearColor(color);
}

int GraphicEngine::Init(const GAME_WINDOW& gameWindow)
{
	g2_InitSdk();

	g2_SetFrameMove(GraphicEngine::Update);
	g2_SetRender(GraphicEngine::Render);

	g2_CreateWin(
		gameWindow.x,
		gameWindow.y,
		gameWindow.scnW, 
		gameWindow.scnH, 
		gameWindow.name.c_str(), 
		gameWindow.bWindowed, 
		gameWindow.scnScale
	);
	return 0;
}

void GraphicEngine::Destroy()
{
	g2_DestroyWin();
}


int GraphicEngine::Run()
{
	auto r = g2_Run();
	return r;
}