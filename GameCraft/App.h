#pragma once
#include "GameTime.h"
#include "GraphicEngine.h"

class GameInput;
class GameScene;

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
	GraphicEngine::GAME_WINDOW m_gameWin
	{
		120, 50,
		960, 600,
		"GameTitle",
		true,
		1.0f
	};

	GraphicEngine m_graphicEngine{};
	GameTime	m_gameTime		 {};
	GameInput*	m_pGameInput	 {};
	GameScene*	m_pGameScene	 {};

};

extern App* g_pApp;
