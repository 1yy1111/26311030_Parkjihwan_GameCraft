#pragma once
#include "GameScene.h"
#include "Player.h"

class ScenePlay : public GameScene
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

private:
    Player m_player{};
};

