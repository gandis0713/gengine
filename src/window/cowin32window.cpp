#include "cowin32window.h"

#include "WinUser.h"


LRESULT CALLBACK windowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT returnValue = 0;

    return returnValue;
}

CoWin32Window::CoWin32Window()
{

}

CoWin32Window::~CoWin32Window()
{

}

void CoWin32Window::initialize()
{
    winClassEx.cbSize        = sizeof(WNDCLASSEX);
    winClassEx.style         = 0;
    winClassEx.lpfnWndProc   = windowProcedure;
    winClassEx.cbClsExtra    = 0;
    winClassEx.cbWndExtra    = 0;
    winClassEx.hInstance     = instance;
    winClassEx.hIcon         = LoadIcon(instance, IDI_APPLICATION);
    winClassEx.hIconSm       = 0;
    winClassEx.hCursor       = LoadCursor(0, IDC_ARROW);
    winClassEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    winClassEx.lpszMenuName  = 0;
    winClassEx.lpszClassName = className;
    winClassEx.hIconSm       = LoadIcon(instance, IDI_APPLICATION);
}



void CoWin32Window::createWindow()
{
    if(!RegisterClassEx(&winClassEx))
    {
        return;
    }

    handle = CreateWindowEx(styleEx,
                            className,
                            title,
                            style,
                            x,
                            y,
                            width,
                            height,
                            parentHandle,
                            menuHandle,
                            instance,
                            (LPVOID)NULL);
}
