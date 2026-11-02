#pragma once
#include "GameScene.h"
#include <string>

class SceneBegin : public GameScene
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

private:
    int m_txTitle{ -1 };
    std::string m_startText{ "PRESS ENTER TO START" };

    long long m_blinkTimer{};
    bool m_isTextVisible {};
};