#pragma once

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual int Init() = 0;
    virtual void Destroy() = 0;
    virtual int Update() = 0;
    virtual int Render() = 0;

protected:
    float m_posX{};
    float m_posY{};
    float m_scale{ 1.0f };
};