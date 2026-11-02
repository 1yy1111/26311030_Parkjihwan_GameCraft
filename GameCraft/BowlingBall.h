#pragma once
#include "GameObject.h"

class BowlingBall : public GameObject
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

private:
    void Reset();

    int m_txBall{ -1 };

    float m_speed{ 180.0f };

    int m_frameIndex{};
    long long m_animTimer{};
};