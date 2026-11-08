#include "GameScene.h"
#include <glc2d.h>

int GameScene::m_txBg{ -1 };
int GameScene::m_font{ -1 };
int GameScene::m_bgm { -1 };

namespace
{
    VEC2 bgScale{ 1.0f, 1.0f };
}

int GameScene::Init()
{
    if (0 > m_txBg)
    {
        m_txBg = g2_TextureLoad("resource/Texture/Background/bg_lane.png", 0);
    }

    if (0 > m_font)
    {
        m_font = g2_FontCreate("NeoµÕ±Ù¸ð", 40);
    }

    if (0 > m_bgm)
    {
        m_bgm = g2_SoundLoad("resource/Sound/BGM/bgm_play.mp3");
    }

    if (0 > m_txBg || 0 > m_font || 0 > m_bgm)
    {
        return -1;
    }

    float bgTexW{ static_cast<float>(g2_TextureWidth(m_txBg)) };
    float bgTexH{ static_cast<float>(g2_TextureHeight(m_txBg)) };

    if (0.0f >= bgTexW || 0.0f >= bgTexH)
    {
        return -1;
    }

    bgScale =
    {
        g2_GetScnW() / bgTexW,
        g2_GetScnH() / bgTexH
    };

    return 0;
}

void GameScene::Destroy()
{
	
}

int GameScene::Update()
{
	return 0;
}

int GameScene::Render()
{
    g2_Draw2D(m_txBg, nullptr, nullptr, &bgScale);

    return 0;
}

void GameScene::ReleaseResources()
{
    if (0 <= m_txBg)
    {
        g2_TextureRelease(m_txBg);
        m_txBg = -1;
    }

    if (0 <= m_bgm)
    {
        g2_SoundStop(m_bgm);
        g2_SoundRelease(m_bgm);
        m_bgm = -1;
    }

    bgScale = { 1.0f, 1.0f };
}
