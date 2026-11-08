
#include "StraightBall.h"
#include <glc2d.h>
#include <random>

namespace
{
    constexpr float BALL_MIN_X{ 160.0f };
    constexpr float BALL_MAX_X{ 864.0f };

    std::mt19937 randomEngine{ std::random_device{}() };
}

int StraightBall::Init()
{
    if (0 > BowlingBall::Init())
    {
        return -1;
    }

    Reset();

    return 0;
}

void StraightBall::Reset()
{
    BowlingBall::Reset();

    std::uniform_real_distribution<float> randomX
    {
        BALL_MIN_X, BALL_MAX_X
    };

    m_targetX = randomX(randomEngine);
}

void StraightBall::UpdateMovement(float progress)
{
    float startX{ g2_GetScnW() / 2.0f };

    m_posX = startX + (m_targetX - startX) * progress;
}
