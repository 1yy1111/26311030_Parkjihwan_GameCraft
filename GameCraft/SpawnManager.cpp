#include "SpawnManager.h"
#include "BowlingBall.h"
#include "StraightBall.h"
#include "CurveBall.h"
#include <random>
#include "Item.h"

namespace
{
    std::mt19937 randomEngine{ std::random_device{}() };
}

void SpawnManager::Init()
{
    m_spawnTimer = 0.0f;
    m_survivalTime = 0.0f;

    m_itemSpawnTimer = 0.0f;
    m_itemSpawnInterval = 12.0f;

    UpdateSpawnInterval();
}

void SpawnManager::Update(float deltaTime, float survivalTime)
{
    m_spawnTimer += deltaTime;
    m_survivalTime = survivalTime;

    m_itemSpawnTimer += deltaTime;
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

std::unique_ptr<BowlingBall> SpawnManager::CreateBall(
    float survivalTime,
    int straightTexture,
    int curveTexture)
{
    // 30초 이전에는 직진만 생성
    if (survivalTime < 30.0f)
    {
        std::unique_ptr<BowlingBall> ball
            = std::make_unique<StraightBall>();

        ball->SetTexture(straightTexture);

        return ball;
    }

    // 30초 이후에는 직진, 커브 같이
    std::uniform_int_distribution<int> randomType{ 0, 1 };

    if (0 == randomType(randomEngine))
    {
        std::unique_ptr<BowlingBall> ball
            = std::make_unique<StraightBall>();

        ball->SetTexture(straightTexture);

        return ball;
    }
    else
    {
        std::unique_ptr<BowlingBall> ball
            = std::make_unique<CurveBall>();

        ball->SetTexture(curveTexture);

        return ball;
    }
}

bool SpawnManager::CanSpawnItem() const
{
    return m_itemSpawnInterval <= m_itemSpawnTimer;
}

void SpawnManager::ResetItemSpawnTimer()
{
    m_itemSpawnTimer = 0.0f;
}

std::unique_ptr<Item> SpawnManager::CreateItem()
{
    return std::make_unique<Item>();
}

