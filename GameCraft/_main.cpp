#include "App.h"

int main()
{
    App app;

    if (0 > g_pApp->Init())
    {
        return 0;
    }

    auto hr = g_pApp->Run();
    //hr
    {
        // 빠져나왔을 때 로그
    }

    return 0;
}