#pragma once
#include "GameScene.h"
#include "Player.h"
#include "StraightBall.h"

class ScenePlay : public GameScene
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

private:
    Player m_player{};
    StraightBall m_ball{};

    bool m_isCollision{};
    float m_collisionTimer{};

    float m_survivalTime{};
    int m_score{};
    int m_scoreFont{ -1 };

    int m_gameOverSound{ -1 };

    bool m_isPaused{};
};