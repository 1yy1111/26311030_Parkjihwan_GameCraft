#pragma once
#include "GameScene.h"
#include "Player.h"
#include "SpawnManager.h"
#include "BowlingBall.h"
#include <vector>
#include <memory>

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

private:
    Player m_player{};
    SpawnManager m_spawnManager{};

    std::vector<std::unique_ptr<BowlingBall>> m_balls{};

    int m_txStraightBall{ -1 };
    int m_txCurveBall{ -1 };

    bool m_isCollision{};
    float m_collisionTimer{};

    float m_survivalTime{};
    int m_score{};
    int m_scoreFont{ -1 };

    int m_gameOverSound{ -1 };

    bool m_isPaused{};
};
