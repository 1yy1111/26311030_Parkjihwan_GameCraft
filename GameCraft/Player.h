#pragma once

class Player
{
public:
    int Init();
    void Destroy();
    int Update();
    int Render();

private:
    int m_txPlayer{ -1 };

    float m_posX{};
    float m_posY{};

    float m_speed{ 300.0f };
    float m_scale{ 0.7f };
};