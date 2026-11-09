#include "CollisionManager.h"
#include "Player.h"
#include "BowlingBall.h"
#include "Item.h"
#include <cmath>

namespace
{
    constexpr float COLLISION_MIN_Y{ 530.0f };
    constexpr float COLLISION_MAX_Y{ 590.0f };

    constexpr float PLAYER_WIDTH{ 256.0f };

    constexpr float BALL_FRAME_WIDTH{ 256.0f };

    constexpr float PLAYER_HIT_RADIUS{ 18.0f };
    constexpr float BALL_HIT_RATIO{ 0.4f };
}

bool CollisionManager::CheckPlayerBall( const Player& player, const BowlingBall& ball )
{
    float ballY{ ball.GetPosY() };

    // 공이 플레이어의 충돌 구간에 있는지 확인
    if (ballY < COLLISION_MIN_Y ||
        COLLISION_MAX_Y < ballY)
    {
        return false;
    }

    float playerCenterX
    {
        player.GetPosX() +
        PLAYER_WIDTH * player.GetScale() / 2.0f
    };

    float ballCenterX{ ball.GetPosX() };

    float ballRadius
    {
        BALL_FRAME_WIDTH * ball.GetScale() * BALL_HIT_RATIO
    };

    float distanceX
    {
        std::fabs(playerCenterX - ballCenterX)
    };

    return distanceX <= (PLAYER_HIT_RADIUS + ballRadius);
}

bool CollisionManager::CheckPlayerItem(const Player& player, const Item& item)
{
    // 아이템 플레이어 충돌 구간
    constexpr float ITEM_COLLISION_MIN_Y{ 530.0f };
    constexpr float ITEM_COLLISION_MAX_Y{ 590.0f };

    constexpr float PLAYER_WIDTH{ 256.0f };
    constexpr float PLAYER_HIT_RADIUS{ 25.0f };
    constexpr float ITEM_HIT_RADIUS{ 35.0f };
        
    float itemY{ item.GetPosY() };

    if (itemY < ITEM_COLLISION_MIN_Y ||
        ITEM_COLLISION_MAX_Y < itemY)
    {
        return false;
    }

    float playerCenterX
    {
        player.GetPosX() +
        PLAYER_WIDTH * player.GetScale() / 2.0f
    };

    float itemCenterX{ item.GetPosX() };

    float distanceX
    {
        std::fabs(playerCenterX - itemCenterX)
    };

    return distanceX <=
        (PLAYER_HIT_RADIUS + ITEM_HIT_RADIUS);
}
