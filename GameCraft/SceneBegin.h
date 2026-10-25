#pragma once
#include "GameScene.h"

class SceneBegin : public GameScene
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;
};

