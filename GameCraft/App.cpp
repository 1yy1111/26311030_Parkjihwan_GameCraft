#include "App.h"
#include "GameInput.h"
#include "GameScene.h"
#include "SceneBegin.h"
#include "ScenePlay.h"
#include "SceneResult.h"
#include <Windows.h>

App* g_pApp{ nullptr };

App::App()
{
    g_pApp = this;

    m_pGameInput = new GameInput;

    m_sceneList.push_back(new SceneBegin);
    m_sceneList.push_back(new ScenePlay); 
    m_sceneList.push_back(new SceneResult); 

    m_pGameScene = m_sceneList[m_sceneCurrent];
}

App::~App()
{
    if (this == g_pApp)
    {
        g_pApp = nullptr;
    }
}

int App::Init()
{
    // glc2d 초기화
    if (0 > m_graphicEngine.Init(m_gameWin))
    {
        return -1;
    }

    m_graphicEngine.SetColor(0xFF006699);

    // GameTime 초기화
    m_gameTime.Init();

    // GameInput 초기화
    if (0 > m_pGameInput->Init())
    {
        Destroy();
        return -2;
    }

    // GameScene 초기화
    if (0 > m_pGameScene->Init())
    {
        Destroy();
        return -3;
    }

    return 0;
}

void App::Destroy()
{
    if (nullptr != m_pGameScene)
    {
        m_pGameScene->Destroy();
        m_pGameScene = nullptr;
    }

    for (GameScene* pScene : m_sceneList)
    {
        delete pScene;
    }

    m_sceneList.clear();

    GameScene::ReleaseResources();

    if (nullptr != m_pGameInput)
    {
        delete m_pGameInput;
        m_pGameInput = nullptr;
    }

    m_graphicEngine.Destroy();
}

int App::Update()
{
    // Scene 전환
    if (m_sceneChanged)
    {
        m_pGameScene->Destroy();

        m_sceneChanged = false;
        m_sceneCurrent = m_sceneNext;
        m_pGameScene = m_sceneList[m_sceneCurrent];

        if (0 > m_pGameScene->Init())
        {
            return -1;
        }
    }

    // GameTime 업데이트
    m_gameTime.Update();

    // GameInput 업데이트
    if (0 > m_pGameInput->Update())
    {
        return -1;
    }

    // GameScene 업데이트
    if (0 > m_pGameScene->Update())
    {
        return -1;
    }

    return 0;
}

int App::Render()
{
    if (0 > m_pGameScene->Render())
    {
        return -1;
    }

    return 0;
}

int App::Run()
{
    m_graphicEngine.Run();

    Destroy();

    return 0;
}

void App::RequestExit()
{
    PostMessage(g2_GetHwnd(), WM_CLOSE, 0, 0);
}

void App::ChangeScene(GAME_PHASE nextScene)
{
    m_sceneChanged = true;
    m_sceneNext = nextScene;
}

long long App::GetDeltaTime() const
{
    return m_gameTime.GetDeltaTime();
}

void App::SetFinalScore(int score)
{
    m_finalScore = score;
}

int App::GetFinalScore() const
{
    return m_finalScore;
}
