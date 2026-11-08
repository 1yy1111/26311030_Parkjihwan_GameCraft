#include "ScenePlay.h"
#include "CollisionManager.h"
#include <glc2d.h>
#include "App.h"

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

    m_survivalTime = 0.0f;
    m_score = 0;

    m_scoreFont = g2_FontCreate("NeoµÕ±Ù¸ð", 24);

    m_isCollision = false;

    return 0;   
}

void ScenePlay::Destroy()
{
    m_ball.Destroy();
    m_player.Destroy();
}


int ScenePlay::Update()
{
    if (m_isCollision)
    {
        return 0;
    }

    if (0 > m_player.Update())
    {
        return -1;
    }

    if (0 > m_ball.Update())
    {
        return -1;
    }

    float deltaTime
    {
        g_pApp->GetDeltaTime() / 1000.0f
    };

    m_survivalTime += deltaTime;
    m_score = static_cast<int>(m_survivalTime);

    if (CollisionManager::CheckPlayerBall(m_player, m_ball))
    {
        m_isCollision = true;

        g2_SetWindowTitle("Collision!");
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

    g2_FontDrawText(
        m_scoreFont,
        { 25, 20 },
        0xFFFFE7B0,
        "SCORE %03d",
        m_score
    );

    return 0;
}