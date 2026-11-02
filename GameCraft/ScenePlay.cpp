#include "ScenePlay.h"

int ScenePlay::Init()
{
    if (0 > GameScene::Init())
    {
        return -1;
    }

    if (0 > m_player.Init())
    {
        return -1;
    }

    if (0 > m_ball.Init())
    {
        m_player.Destroy();
        return -1;
    }

    return 0;
}

void ScenePlay::Destroy()
{
    m_ball.Destroy();
    m_player.Destroy();
}

int ScenePlay::Update()
{
    if (0 > m_player.Update())
    {
        return -1;
    }

    if (0 > m_ball.Update())
    {
        return -1;
    }

    return 0;
}

int ScenePlay::Render()
{
    if (0 > GameScene::Render())
    {
        return -1;
    }

    
    m_ball.Render();
    
    m_player.Render();

    return 0;
}