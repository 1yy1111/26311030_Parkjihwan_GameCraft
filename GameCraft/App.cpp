#include "App.h"

App::App()
{

}

App::~App()
{

}

int App::Init()
{
	return 0;
}

void App::Destroy()
{
}

int App::Update()
{
	return 0;
}

int App::Render()
{
	return 0;
}

int App::Run()
{
	m_graphicEngine.Run();

	this->Destroy();
	return 0;
}
