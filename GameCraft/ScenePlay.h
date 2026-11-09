#pragma once
#include "GameScene.h"
#include "Player.h"
#include "SpawnManager.h"
#include "BowlingBall.h"
#include <vector>
#include <memory>
#include "Item.h"

class ScenePlay : public GameScene
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

private:
    int SpawnBall();
    int UpdateBalls();
    void RenderBalls();

    int SpawnItem();
    int UpdateItems();
    void RenderItems();

private:
    Player m_player{};
    SpawnManager m_spawnManager{};

    std::vector<std::unique_ptr<BowlingBall>> m_balls{};
    std::vector<std::unique_ptr<Item>> m_items{};

    int m_txSpeedItem{ -1 };

    int m_txStraightBall{ -1 };
    int m_txCurveBall{ -1 };

    bool m_isCollision{};
    float m_collisionTimer{};

    float m_survivalTime{};
    int m_score{};
    int m_scoreFont{ -1 };

    int m_gameOverSound{ -1 };
    int m_itemPickupSound{ -1 };

    bool m_isPaused{};
};
