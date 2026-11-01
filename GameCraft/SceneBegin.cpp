#include "SceneBegin.h"

int SceneBegin::Init()
{
    return GameScene::Init();
}

void SceneBegin::Destroy()
{
    GameScene::Destroy();
}

int SceneBegin::Update()
{
    return 0;
}

int SceneBegin::Render()
{
    return GameScene::Render();
}