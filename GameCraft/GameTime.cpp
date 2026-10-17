#include "GameTime.h"
#include "glc2d.h"

int GameTime::Init()
{
    m_beginTime = g2_TimeGetTime();
    m_previousTime = m_beginTime;

    m_elapsedTime = 0;
    m_deltaTime = 0;

    return 0;
}

int GameTime::Update()
{
    long long currentTime{ g2_TimeGetTime() };

    m_elapsedTime = currentTime - m_beginTime;
    m_deltaTime = currentTime - m_previousTime;

    m_previousTime = currentTime;

    return 0;
}

long long GameTime::GetElapsedTime() const
{
    return m_elapsedTime;
}

long long GameTime::GetDeltaTime() const
{
    return m_deltaTime;
}

float GameTime::GetDeltaSeconds() const
{
    return static_cast<float>(m_deltaTime) / 1000.0f;
}