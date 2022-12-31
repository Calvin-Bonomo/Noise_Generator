#include "Window.h"

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
    return m_hwnd != NULL;
}

LRESULT Window::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) 
{

}