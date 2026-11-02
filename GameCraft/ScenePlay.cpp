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

    return 0;
}

void ScenePlay::Destroy()
{
    m_player.Destroy();
}

int ScenePlay::Update()
{
    return m_player.Update();
}

int ScenePlay::Render()
{
    if (0 > GameScene::Render())
    {
        return -1;
    }

    return m_player.Render();
}