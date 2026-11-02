#pragma once
#include "Character.h"

class Player : public Character
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

private:
    int m_txPlayer{ -1 };
};