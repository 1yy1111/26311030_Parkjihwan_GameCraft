#include "SpawnManager.h"
#include "BowlingBall.h"
#include "StraightBall.h"
#include <random>

namespace
{
    std::mt19937 randomEngine{ std::random_device{}() };
}

void SpawnManager::Init()
{
    m_spawnTimer = 0.0f;
    m_survivalTime = 0.0f;

    UpdateSpawnInterval();
}

void SpawnManager::Update(float deltaTime, float survivalTime)
{
    m_spawnTimer += deltaTime;
    m_survivalTime = survivalTime;
}

bool SpawnManager::CanSpawn() const
{
    return m_spawnInterval <= m_spawnTimer;
}

void SpawnManager::ResetSpawnTimer()
{
    m_spawnTimer = 0.0f;

    UpdateSpawnInterval();
}

void SpawnManager::UpdateSpawnInterval()
{
    float minInterval{};
    float maxInterval{};

    if (m_survivalTime < 10.0f)
    {
        minInterval = 0.9f;
        maxInterval = 1.3f;
    }
    else if (m_survivalTime < 30.0f)
    {
        minInterval = 0.9f;
        maxInterval = 1.3f;
    }
    else if (m_survivalTime < 60.0f)
    {
        minInterval = 0.75f;
        maxInterval = 1.1f;
    }
    else
    {
        minInterval = 0.65f;
        maxInterval = 0.95f;
    }

    std::uniform_real_distribution<float> randomInterval
    {
        minInterval, maxInterval
    };

    m_spawnInterval = randomInterval(randomEngine);
}

std::unique_ptr<BowlingBall> SpawnManager::CreateStraightBall()
{
    return std::make_unique<StraightBall>();
}
