#pragma once
#include "GameObject.h"

enum class ItemType
{
    Speed,
    Invincible,
    Gun
};

class Item : public GameObject
{
public:
    int Init() override;
    void Destroy() override;
    int Update() override;
    int Render() override;

    void SetTexture(int textureId);
    bool IsOutOfScreen() const;

    ItemType GetType() const;

private:
    int m_txItem{ -1 };
    ItemType m_type{ ItemType::Speed };

    float m_speed{ 180.0f };

    float m_targetX{};
};
