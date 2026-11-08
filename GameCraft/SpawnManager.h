#pragma once
#include <memory>

class BowlingBall;

class SpawnManager
{
public:
    void Init();

    void Update(float deltaTime);

    bool CanSpawn() const;
    void ResetSpawnTimer();

    std::unique_ptr<BowlingBall> CreateStraightBall();

private:
    float m_spawnTimer{};
    float m_spawnInterval{ 2.0f };
};
