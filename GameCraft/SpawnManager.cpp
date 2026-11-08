#include "SpawnManager.h"
#include "BowlingBall.h"
#include "StraightBall.h"

void SpawnManager::Init()
{
    m_spawnTimer = 0.0f;
    m_spawnInterval = 0.8f;
}

void SpawnManager::Update(float deltaTime)
{
    m_spawnTimer += deltaTime;
}

bool SpawnManager::CanSpawn() const
{
    return m_spawnInterval <= m_spawnTimer;
}

void SpawnManager::ResetSpawnTimer()
{
    m_spawnTimer = 0.0f;
}

std::unique_ptr<BowlingBall> SpawnManager::CreateStraightBall()
{
    return std::make_unique<StraightBall>();
}
