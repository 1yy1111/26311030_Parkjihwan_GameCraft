#include "Character.h"

void Character::Move(float direction, float deltaTime)
{
    m_posX += direction * m_speed * deltaTime;
}