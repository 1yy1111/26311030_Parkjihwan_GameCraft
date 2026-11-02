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

    static constexpr long long BLINK_INTERVAL{ 500 };
    long long m_blinkTimer{};
    bool m_isTextVisible {};
};