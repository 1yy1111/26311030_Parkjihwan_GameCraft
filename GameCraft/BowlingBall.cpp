#include "BowlingBall.h"
#include "App.h"
#include <glc2d.h>
#include <algorithm>
#include <random>

namespace
{
    // 스프라이트 시트
    constexpr int BALL_FRAME_WIDTH{ 256 };
    constexpr int BALL_FRAME_HEIGHT{ 256 };
    constexpr int BALL_FRAME_COUNT{ 8 };

    // 애니메이션 간격 (ms)
    constexpr long long BALL_ANIM_INTERVAL{ 120 };

    // 볼링공 이동 범위
    constexpr float BALL_START_Y{ 160.0f };
    constexpr float BALL_END_Y{ 600.0f };

    // 볼링공 크기
    constexpr float BALL_MIN_SCALE{ 0.1f };
    constexpr float BALL_MAX_SCALE{ 0.6f };
}

int BowlingBall::Init()
{
    BowlingBall::Reset();

    m_frameIndex = 0;
    m_animTimer = 0;

    return 0;
}

void BowlingBall::Destroy()
{
    if (0 <= m_txBall)
    {
        g2_TextureRelease(m_txBall);
        m_txBall = -1;
    }
}

void BowlingBall::Reset()
{
    m_posX = g2_GetScnW() / 2.0f;
    m_posY = BALL_START_Y;
    m_scale = BALL_MIN_SCALE;
}

int BowlingBall::Update()
{
    long long deltaTime{ g_pApp->GetDeltaTime() };

    m_animTimer += deltaTime;

    if (BALL_ANIM_INTERVAL <= m_animTimer)
    {
        m_frameIndex = (m_frameIndex + 1) % BALL_FRAME_COUNT;
        m_animTimer -= BALL_ANIM_INTERVAL;
    }

    // 이동 진행도 계산
    float progress
    {
        (m_posY - BALL_START_Y) / (BALL_END_Y - BALL_START_Y)
    };

    progress = std::clamp(progress, 0.0f, 1.0f);

    // 이동 속도 계산
    float currentSpeed{ m_speed * (1.0f + progress * 0.25f) };

    m_posY += currentSpeed * (deltaTime / 1000.0f);

    // 이동 후 진행도 갱신
    progress = (m_posY - BALL_START_Y)
        / (BALL_END_Y - BALL_START_Y);

    progress = std::clamp(progress, 0.0f, 1.0f);

    // 공 종류에 따른 이동 패턴
    UpdateMovement(progress);

    // 원근감에 따른 크기 변화
    m_scale = BALL_MIN_SCALE
        + (BALL_MAX_SCALE - BALL_MIN_SCALE) * progress;

    if (BALL_END_Y <= m_posY)
    {
        Reset();
    }

    return 0;
}

int BowlingBall::Render()
{
    RECT source
    {
        m_frameIndex * BALL_FRAME_WIDTH,
        0,
        (m_frameIndex + 1) * BALL_FRAME_WIDTH,
        BALL_FRAME_HEIGHT
    };

    float width{ BALL_FRAME_WIDTH * m_scale };
    float height{ BALL_FRAME_HEIGHT * m_scale };

    VEC2 position
    {
        m_posX - width / 2.0f,
        m_posY - height / 2.0f
    };

    VEC2 scale{ m_scale, m_scale };

    g2_Draw2D(m_txBall, &source, &position, &scale);

    return 0;
}