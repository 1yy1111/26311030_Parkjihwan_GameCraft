
#pragma once
#include <memory>

class BowlingBall;

class SpawnManager
{
public:
    void Init();

    void Update(float deltaTime, float survivalTime);

    bool CanSpawn() const;
    void ResetSpawnTimer();

    std::unique_ptr<BowlingBall> CreateStraightBall();

private:
    void UpdateSpawnInterval();

private:
    float m_spawnTimer{};
    float m_spawnInterval{ 1.0f };
    float m_survivalTime{};
};
