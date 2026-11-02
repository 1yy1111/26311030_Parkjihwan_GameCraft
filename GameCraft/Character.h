#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
    virtual ~Character() = default;

protected:
    float m_speed{ 300.0f };

    void Move(float direction, float deltaTime);
};