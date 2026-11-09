#pragma once
#include "Character.h"

class Player : public Character
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

    void ActivateSpeedBoost();
    void UpdateSpeedBoost(float deltaTime);

    bool IsSpeedBoostActive() const;
    float GetSpeedBoostRemainingTime() const;

private:
    int m_txPlayer{ -1 };

    float m_speedBoostTimer{};
    bool m_isSpeedBoostActive{};
};