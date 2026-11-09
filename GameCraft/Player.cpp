#include "Player.h"
#include "App.h"
#include "GameInput.h"
#include <glc2d.h>
#include <algorithm>

namespace
{
    constexpr float PLAYER_MIN_X{ -15.0f };
    constexpr float PLAYER_MAX_X{ 870.0f };
    constexpr float PLAYER_Y{ 450.0f }; 

    constexpr float SPEED_BOOST_DURATION{ 5.0f };
    constexpr float SPEED_BOOST_MULTIPLIER{ 1.5f };
}

int Player::Init()
{
    m_txPlayer = g2_TextureLoad("resource/Texture/Player/pin.png", 0);

    if (0 > m_txPlayer)
    {
        return -1;
    }

    m_scale = 0.7f;

    float playerWidth
    {
        g2_TextureWidth(m_txPlayer) * m_scale
    };

    m_posX = (g2_GetScnW() - playerWidth) / 2.0f;
    m_posY = PLAYER_Y;

    m_speedBoostTimer = 0.0f;
    m_isSpeedBoostActive = false;

    return 0;
}

void Player::Destroy()
{
    if (0 <= m_txPlayer)
    {
        g2_TextureRelease(m_txPlayer);
        m_txPlayer = -1;
    }
}

int Player::Update()
{
    float deltaTime{ g_pApp->GetDeltaTime() / 1000.0f };

    float speedMultiplier{ 1.0f };

    if (m_isSpeedBoostActive)
    {
        speedMultiplier = SPEED_BOOST_MULTIPLIER;
    }

    if (GetGameInput()->IsMoveLeft())
    {
        Move(-1.0f, deltaTime * speedMultiplier);
    }

    if (GetGameInput()->IsMoveRight())
    {
        Move(1.0f, deltaTime * speedMultiplier);
    }

    m_posX = std::clamp(m_posX, PLAYER_MIN_X, PLAYER_MAX_X);

    return 0;
}


int Player::Render()
{
    VEC2 position{ m_posX, m_posY };
    VEC2 scale{ m_scale, m_scale };

    g2_Draw2D(m_txPlayer, nullptr, &position, &scale);

    return 0;
}

void Player::ActivateSpeedBoost()
{
    m_speedBoostTimer = SPEED_BOOST_DURATION;
    m_isSpeedBoostActive = true;
}

void Player::UpdateSpeedBoost(float deltaTime)
{
    if (!m_isSpeedBoostActive)
    {
        return;
    }

    m_speedBoostTimer -= deltaTime;

    if (m_speedBoostTimer <= 0.0f)
    {
        m_speedBoostTimer = 0.0f;
        m_isSpeedBoostActive = false;
    }
}

bool Player::IsSpeedBoostActive() const
{
    return m_isSpeedBoostActive;
}

float Player::GetSpeedBoostRemainingTime() const
{
    return m_speedBoostTimer;
}
