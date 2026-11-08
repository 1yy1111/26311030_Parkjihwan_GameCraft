#pragma once

class Player;
class BowlingBall;
class Item;

class CollisionManager
{
public:
    static bool CheckPlayerBall(
        const Player& player,
        const BowlingBall& ball
    );

    static bool CheckPlayerItem(
        const Player& player,
        const Item& item
    );

    static bool CheckMouseBall(
        float mouseX,
        float mouseY,
        const BowlingBall& ball
    );
};