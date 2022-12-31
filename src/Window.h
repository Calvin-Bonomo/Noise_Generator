#ifndef UNICODE
#define UNICODE
#endif

#include "windows.h"

class Window
{
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
    {
        Window* pThis = nullptr;
        pThis = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        if (pThis) 
        {
            return pThis->HandleMessage(uMsg, wParam, lParam);
        }
        else 
        {
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    bool MakeWindow(HINSTANCE hInstance, wchar_t* windowTitle);
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

    HWND GetWindowHandle() { return m_hwnd; };
private:
    const wchar_t* CLASS_NAME = L"Noise Generator";
    WNDCLASS m_wc;
    HWND m_hwnd;
};