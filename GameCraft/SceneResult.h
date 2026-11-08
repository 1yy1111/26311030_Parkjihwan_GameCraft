#pragma once
#include "GameScene.h"

class SceneResult : public GameScene
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;
};