#ifndef UNICODE
#define UNICODE
#endif

#ifdef DEBUG
#include "debug/DebugTools.h"
#endif

#include "windows.h"
#include <stdio.h>
#include <string>

#include "NoiseGeneratorAppConfig.h"
#include "Window.h"

int APIENTRY WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) 
{
    Window* window = new Window();
    if (!window->MakeWindow(hInstance, const_cast<wchar_t*>(APP_TITLE))) 
    {
        return 1;
    }

    ShowWindow(window->GetWindowHandle(), nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}