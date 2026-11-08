
#pragma once
#include "GameObject.h"

class BowlingBall : public GameObject
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

    void SetTexture(int textureId);
    bool IsOutOfScreen() const;

protected:
    virtual void UpdateMovement(float progress) = 0;
    virtual void Reset();

    int m_txBall{ -1 };

    float m_speed{ 240.0f };

private:
    int m_frameIndex{};
    long long m_animTimer{};
};
