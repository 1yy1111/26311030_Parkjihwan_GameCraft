#include "Item.h"
#include "App.h"
#include <glc2d.h>
#include <algorithm>
#include <random>

namespace
{
    constexpr float ITEM_START_Y{ 160.0f };
    constexpr float ITEM_END_Y{ 600.0f };

    constexpr float ITEM_MIN_X{ 300.0f };
    constexpr float ITEM_MAX_X{ 724.0f };

    constexpr float ITEM_MIN_SCALE{ 0.2f };
    constexpr float ITEM_MAX_SCALE{ 0.7f };

    std::mt19937 randomEngine{ std::random_device{}() };
}

int Item::Init()
{
    if (0 > m_txItem)
    {
        return -1;
    }

    std::uniform_real_distribution<float> randomX
    {
        ITEM_MIN_X, ITEM_MAX_X
    };

    m_posX = g2_GetScnW() / 2.0f;
    m_posY = ITEM_START_Y;
    m_scale = ITEM_MIN_SCALE;

    m_targetX = randomX(randomEngine);

    return 0;
}


void Item::Destroy()
{

}

int Item::Update()
{
    float deltaTime
    {
        g_pApp->GetDeltaTime() / 1000.0f
    };

    m_posY += m_speed * deltaTime;

    float progress
    {
        (m_posY - ITEM_START_Y) /
        (ITEM_END_Y - ITEM_START_Y)
    };

    progress = std::clamp(progress, 0.0f, 1.0f);

    float startX{ g2_GetScnW() / 2.0f };

    m_posX = startX + (m_targetX - startX) * progress;

    m_scale = ITEM_MIN_SCALE +
        (ITEM_MAX_SCALE - ITEM_MIN_SCALE) * progress;

    return 0;
}

int Item::Render()
{
    float width{ 128.0f * m_scale };
    float height{ 128.0f * m_scale };

    VEC2 position
    {
        m_posX - width / 2.0f,
        m_posY - height / 2.0f
    };

    VEC2 scale{ m_scale, m_scale };

    g2_Draw2D(
        m_txItem,
        nullptr,
        &position,
        &scale
    );

    return 0;
}

void Item::SetTexture(int textureId)
{
    m_txItem = textureId;
}

bool Item::IsOutOfScreen() const
{
    return ITEM_END_Y <= m_posY;
}

ItemType Item::GetType() const
{
    return m_type;
}
