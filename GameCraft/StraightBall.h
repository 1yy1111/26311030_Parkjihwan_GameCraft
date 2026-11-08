#pragma once
#include "BowlingBall.h"

class StraightBall : public BowlingBall
{
public:
    int Init() override;

protected:
    void UpdateMovement(float progress) override;
    void Reset() override;

private:
    float m_targetX{};
};
