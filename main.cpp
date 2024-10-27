#include <Windows.h>
#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include "WorkWindow.h"
#include "WinMouseEventPublisher.h"
HHOOK hMouseHook;

LRESULT CALLBACK
MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == 0) {
        switch (wParam) {
        case WM_LBUTTONUP: {
            std::cerr << "left button released\n";
            break;
        }
        case WM_LBUTTONDOWN: {
            std::cerr << "left button pressed\n";
            break;
        }
        case WM_RBUTTONUP: {
            std::cerr << "right button released\n";
            break;
        }
        case WM_RBUTTONDOWN: {
            std::cerr << "right button pressed\n";
            break;
        }
        }
    }
    return CallNextHookEx(hMouseHook, nCode, wParam, lParam);
}

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    WorkWindow window;


    int ret = app.exec();
    return ret;
}