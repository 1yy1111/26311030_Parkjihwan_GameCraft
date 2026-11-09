#pragma once
#include <memory>

class BowlingBall;
class Item;

class SpawnManager
{
public:
    void Init();

    void Update(float deltaTime, float survivalTime);

    bool CanSpawn() const;
    void ResetSpawnTimer();

    std::unique_ptr<BowlingBall> CreateBall(
        float survivalTime,
        int straightTexture,
        int curveTexture
    );

    bool CanSpawnItem() const;
    void ResetItemSpawnTimer();

    std::unique_ptr<Item> CreateItem();

private:
    void UpdateSpawnInterval();

private:
    float m_spawnTimer{};
    float m_spawnInterval{ 1.0f };
    float m_survivalTime{};

    float m_itemSpawnTimer{};
    float m_itemSpawnInterval{ 12.0f };
};
