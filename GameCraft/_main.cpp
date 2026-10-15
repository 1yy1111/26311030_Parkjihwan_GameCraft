#include "App.h"

App* g_pApp;

int main()
{
	App app;
	g_pApp = &app;

	if (0 > g_pApp->Init())
	{
		return 0;
	}

	auto hr = g_pApp->Run();
	//hr
	{
		//빠져나왔을때 로그
	}

	return 0;
}