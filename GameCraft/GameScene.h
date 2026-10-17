#pragma once

class GameScene
{
public:
    virtual ~GameScene() = default;

    virtual int Init() = 0;
    virtual void Destroy() = 0;
    virtual int Update() = 0;
    virtual int Render() = 0;
};

