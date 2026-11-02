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
}

int Player::Init()
{
    m_txPlayer = g2_TextureLoad("resource/Texture/Player/pin.png", 0);

    if (0 > m_txPlayer)
    {
        return -1;
    }

    float playerWidth
    {
        g2_TextureWidth(m_txPlayer) * m_scale
    };

    // 화면 가로 중앙에서 시작
    m_posX = (g2_GetScnW() - playerWidth) / 2.0f;
    m_posY = PLAYER_Y;

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

    if (GetGameInput()->IsMoveLeft())
    {
        m_posX -= m_speed * deltaTime;
    }

    if (GetGameInput()->IsMoveRight())
    {
        m_posX += m_speed * deltaTime;
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