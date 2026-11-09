#include "ScenePlay.h"
#include "CollisionManager.h"
#include <glc2d.h>
#include "App.h"
#include "GameInput.h"
#include <algorithm>

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

    m_txStraightBall = g2_TextureLoad( "resource/Texture/Ball/ball_red_roll.png", 0 );

    if (0 > m_txStraightBall)
    {
        m_player.Destroy();
        return -1;
    }

    m_spawnManager.Init();
    m_balls.clear();

    if (0 > SpawnBall())
    {
        return -1;
    }

    m_survivalTime = 0.0f;
    m_score = 0;
    m_scoreFont = g2_FontCreate("Neo둥근모", 24);

    m_isCollision = false;
    m_collisionTimer = 0.0f;

    m_gameOverSound = g2_SoundLoad( "resource/Sound/SFX/game_over.mp3" );

    if (0 > m_gameOverSound)
    {
        return -1;
    }

    if (!g2_SoundIsPlaying(m_bgm))
    {
        g2_SoundReset(m_bgm);
        g2_SoundPlay(m_bgm, true);
    }

    m_isPaused = false;

    return 0;   
}

void ScenePlay::Destroy()
{
    m_balls.clear();

    if (0 <= m_txStraightBall)
    {
        g2_TextureRelease(m_txStraightBall);
        m_txStraightBall = -1;
    }

    m_player.Destroy();

    if (0 <= m_gameOverSound)
    {
        g2_SoundRelease(m_gameOverSound);
        m_gameOverSound = -1;
    }
}

int ScenePlay::Update()
{
    // ESC로 일시정지 및 재개
    if (!m_isCollision && GetGameInput()->IsEscPressed())
    {
        m_isPaused = !m_isPaused;
    }

    if (m_isPaused)
    {
        return 0;
    }

    float deltaTime
    {
        g_pApp->GetDeltaTime() / 1000.0f
    };

    // 충돌 후 결과 화면 전환
    if (m_isCollision)
    {
        m_collisionTimer += deltaTime;

        if (m_collisionTimer >= 0.5f)
        {
            g_pApp->ChangeScene(SCENE_RESULT);
        }

        return 0;
    }

    m_survivalTime += deltaTime;
    m_score = static_cast<int>(m_survivalTime);

    if (0 > m_player.Update())
    {
        return -1;
    }

    // 처음 10초는 공 하나씩 등장
    if (m_survivalTime < 10.0f)
    {
        if (m_balls.empty())
        {
            if (0 > SpawnBall())
            {
                return -1;
            }
        }

        m_spawnManager.ResetSpawnTimer();
    }
    else
    {
        m_spawnManager.Update(deltaTime, m_survivalTime);

        if (m_spawnManager.CanSpawn())
        {
            if (0 > SpawnBall())
            {
                return -1;
            }

            m_spawnManager.ResetSpawnTimer();
        }
    }

    if (0 > UpdateBalls())
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

    
    RenderBalls();
    
    m_player.Render();

    g2_FontDrawText(
        m_scoreFont,
        { 25, 20 },
        0xFFFFE7B0,
        "SCORE %03d",
        m_score
    );

    if (m_isPaused)
    {
        RECT panelSource{ 0, 0, 1, 1 };
        VEC2 panelPos{ 262.0f, 190.0f };
        VEC2 panelScale{ 500.0f, 220.0f };

        g2_Draw2D(
            m_txBg,
            &panelSource,
            &panelPos,
            &panelScale,
            nullptr,
            0.0f,
            0xD9101827,
            true
        );

        g2_FontDrawText(
            m_font,
            { 425, 240 },
            0xFFFFE7B0,
            "PAUSED"
        );

        g2_FontDrawText(
            m_font,
            { 310, 330 },
            0xFFFFFFFF,
            "PRESS ESC TO RESUME"
        );

    }

    return 0;
}

int ScenePlay::SpawnBall()
{
    std::unique_ptr<BowlingBall> ball
        = m_spawnManager.CreateStraightBall();

    if (!ball)
    {
        return -1;
    }

    ball->SetTexture(m_txStraightBall);

    if (0 > ball->Init())
    {
        return -1;
    }

    m_balls.push_back(std::move(ball));

    return 0;
}

int ScenePlay::UpdateBalls()
{
    for (auto& ball : m_balls)
    {
        if (0 > ball->Update())
        {
            return -1;
        }

        if (CollisionManager::CheckPlayerBall(m_player, *ball))
        {
            m_isCollision = true;
            m_collisionTimer = 0.0f;

            g_pApp->SetFinalScore(m_score);

            g2_SoundStop(m_bgm);

            g2_SoundReset(m_gameOverSound);
            g2_SoundPlay(m_gameOverSound);

            return 0;
        }
    }

    // 화면 아래로 지나간 공 제거
    m_balls.erase(
        std::remove_if(
            m_balls.begin(),
            m_balls.end(),
            [](const std::unique_ptr<BowlingBall>& ball)
            {
                return ball->IsOutOfScreen();
            }
        ),
        m_balls.end()
    );

    return 0;
}

void ScenePlay::RenderBalls()
{
    for (auto& ball : m_balls)
    {
        ball->Render();
    }
}
