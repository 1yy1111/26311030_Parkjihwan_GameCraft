// link the 2d game library
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

int GraphicEngine::Init()
{
	// sdk 초기화
	g2_InitSdk();
	

	g2_SetRender(Render);
	g2_SetFrameMove(Update);


	// 윈도우 생성
	g2_CreateWin(100, 100, 1024, 600, "My First Game Window");

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