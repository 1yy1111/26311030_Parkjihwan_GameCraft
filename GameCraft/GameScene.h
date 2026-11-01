#pragma once

enum GAME_PHASE : int
{
    SCENE_BEGIN = 0,
    SCENE_PLAY,
    SCENE_PLAYRESULT,
};

class GameScene
{
public:
    virtual ~GameScene() = default;

    virtual int Init();
    virtual void Destroy();
    virtual int Update();
    virtual int Render();

    static void ReleaseResources();

protected:
    static int m_txBg;
    static int m_font;
    static int m_bgm;
};