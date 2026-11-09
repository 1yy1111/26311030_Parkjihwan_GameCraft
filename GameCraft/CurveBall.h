#pragma once
#include "BowlingBall.h"

class CurveBall : public BowlingBall
{
public:
    int Init() override;

protected:
    void UpdateMovement(float progress) override;
    void Reset() override;

private:
    float m_targetX{};
    float m_curveAmount{};
};
