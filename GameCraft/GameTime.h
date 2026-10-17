#pragma once

class GameTime
{
public:
    int Init();
    int Update();

    long long GetElapsedTime() const;
    long long GetDeltaTime  () const;
    float GetDeltaSeconds   () const;

private:
    long long m_beginTime   {};
    long long m_previousTime{};
    long long m_elapsedTime {};
    long long m_deltaTime   {};
};