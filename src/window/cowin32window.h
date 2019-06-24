#ifndef COWIN32WINDOW_H
#define COWIN32WINDOW_H

#include "cowindow.h"
#include "dedatatype.h"

#ifdef WIN32
#include <windows.h>
#include <wingdi.h>

class CoWin32Window : CoWindow
{
public:
    explicit CoWin32Window();
    ~CoWin32Window();

    void initialize() override;
    void createWindow() override;

private:

    WNDCLASSEX winClassEx;

    DWORD style;
    DWORD styleEx;

    Gwchar title[256];
    Gwchar className[256];

    Gint x;
    Gint y;
    Gint width;
    Gint height;

    HWND handle;
    HWND parentHandle;
    HMENU menuHandle;

    HINSTANCE instance;
};

#endif


#endif // COWIN32WINDOW_H
