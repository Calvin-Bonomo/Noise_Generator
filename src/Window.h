#ifndef UNICODE
#define UNICODE
#endif

#include "windows.h"
#include <iostream>

#ifdef DEBUG
#include "debug/DebugTools.h"
#endif

#ifndef WINDOW_H
#define WINDOW_H
class Window
{
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    bool MakeWindow(HINSTANCE hInstance, wchar_t* windowTitle);
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

    HWND GetWindowHandle() { return m_hwnd; };
private:
    const wchar_t* CLASS_NAME = L"Noise Generator";
    WNDCLASS m_wc;
    HWND m_hwnd;
};
#endif