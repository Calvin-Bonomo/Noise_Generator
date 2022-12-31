#include "Window.h"

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    Window* pThis = nullptr;
    pThis = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (pThis != nullptr) 
    {
        return pThis->HandleMessage(uMsg, wParam, lParam);
    }
    else 
    {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

bool Window::MakeWindow(HINSTANCE hInstance, wchar_t* windowTitle) 
{
    m_wc.lpfnWndProc = WindowProc;
    m_wc.hInstance = hInstance;
    m_wc.lpszClassName = CLASS_NAME;

    RegisterClass(&m_wc);

    m_hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        windowTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    DLOG("Successfully created window!");

    return m_hwnd != NULL;
}

LRESULT Window::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        KILLCONSOLE;
        return 0;
    case WM_PAINT:
        return 0;
    }
}