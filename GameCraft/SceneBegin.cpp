#include "SceneBegin.h"
#include <glc2d.h>
#include "App.h"
#include "GameInput.h"

int SceneBegin::Init()
{
    if (0 > GameScene::Init())
    {
        return -1;
    }

    m_txTitle = g2_TextureLoad("resource/Texture/UI/title_logo.png", 0);

    if (0 > m_txTitle)
    {
        return -1;
    }

    m_blinkTimer = 0;
    m_isTextVisible = true;

    return 0;
}

void SceneBegin::Destroy()
{
    if (0 <= m_txTitle)
    {
        g2_TextureRelease(m_txTitle);
        m_txTitle = -1;
    }
}

int SceneBegin::Update()
{
    m_blinkTimer += g_pApp->GetDeltaTime();

    if (BLINK_INTERVAL <= m_blinkTimer)
    {
        m_isTextVisible = !m_isTextVisible;
        m_blinkTimer -= BLINK_INTERVAL;
    }

    if (GetGameInput()->IsEnterPressed())
    {
        g_pApp->ChangeScene(SCENE_PLAY);
    }

    return 0;
}

int SceneBegin::Render()
{
    if (0 > GameScene::Render())
    {
        return -1;
    }

    VEC2 titleScale{ 0.65f, 0.65f };
    VEC2 titlePos{ 304.0f, 60.0f };

    g2_Draw2D(m_txTitle, nullptr, &titlePos, &titleScale);

    RECT textRect{ 310, 390, 850, 450 };

    if (m_isTextVisible)
    {
        g2_FontDrawText(
            m_font,
            textRect,
            0xFF17243D,
            m_startText.c_str()
        );
    }
    return 0;
}
