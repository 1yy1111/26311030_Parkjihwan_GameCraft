#include "CurveBall.h"
#include <glc2d.h>
#include <random>
#include <cmath>

namespace
{
    constexpr float PI{ 3.14159265f };

    constexpr float BALL_MIN_X{ 300.0f };
    constexpr float BALL_MAX_X{ 724.0f };

    constexpr float CURVE_MIN_AMOUNT{ 50.0f };
    constexpr float CURVE_MAX_AMOUNT{ 90.0f };

    std::mt19937 randomEngine{ std::random_device{}() };
}

int CurveBall::Init()
{
    if (0 > BowlingBall::Init())
    {
        return -1;
    }

    Reset();

    return 0;
}

void CurveBall::Reset()
{
    BowlingBall::Reset();

    std::uniform_real_distribution<float> randomX
    {
        BALL_MIN_X, BALL_MAX_X
    };

    std::uniform_real_distribution<float> randomCurve
    {
        CURVE_MIN_AMOUNT, CURVE_MAX_AMOUNT
    };

    std::uniform_int_distribution<int> randomDirection{ 0, 1 };

    m_targetX = randomX(randomEngine);
    m_curveAmount = randomCurve(randomEngine);

    if (0 == randomDirection(randomEngine))
    {
        m_curveAmount = -m_curveAmount;
    }
}

void CurveBall::UpdateMovement(float progress)
{
    float startX{ g2_GetScnW() / 2.0f };

    float straightX
    {
        startX + (m_targetX - startX) * progress
    };

    float curveX
    {
        m_curveAmount * std::sin(PI * progress)
    };

    m_posX = straightX + curveX;
}
