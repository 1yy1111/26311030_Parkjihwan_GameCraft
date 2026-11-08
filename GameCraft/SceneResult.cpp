#include "SceneResult.h"
#include "App.h"
#include "GameInput.h"
#include <glc2d.h>

int SceneResult::Init()
{
    if (0 > GameScene::Init())
    {
        return -1;
    }

    return 0;
}

void SceneResult::Destroy()
{
}

int SceneResult::Update()
{
    if (GetGameInput()->IsEscPressed())
    {
        g_pApp->RequestExit();
        return 0;
    }

    if (GetGameInput()->IsEnterPressed())
    {
        g_pApp->ChangeScene(SCENE_PLAY);
    }

    return 0;
}

int SceneResult::Render()
{
    if (0 > GameScene::Render())
    {
        return -1;
    }

    // 중앙 반투명 패널
    RECT panelSource{ 0, 0, 1, 1 };
    VEC2 panelPos{ 242.0f, 125.0f };
    VEC2 panelScale{ 540.0f, 350.0f };

    g2_Draw2D(
        m_txBg,
        &panelSource,
        &panelPos,
        &panelScale,
        nullptr,
        0.0f,
        0xD9101827,
        true
    );

    int finalScore{ g_pApp->GetFinalScore() };

    g2_FontDrawText(
        m_font,
        { 385, 175 },
        0xFFFF7777,
        "GAME OVER"
    );

    g2_FontDrawText(
        m_font,
        { 405, 270 },
        0xFFFFFFFF,
        "SCORE %03d",
        finalScore
    );

    g2_FontDrawText(
        m_font,
        { 300, 385 },
        0xFFFFE7B0,
        "PRESS ENTER TO RESTART"
    );
}
