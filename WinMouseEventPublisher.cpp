#include <windows.h>
#include "WinMouseEventPublisher.h"

static HHOOK& getGlobalMouseHook()
{
    static HHOOK hMouseHook = nullptr;
    return hMouseHook;
}

static LRESULT
GlobalMouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION) {
        const MSLLHOOKSTRUCT* mouseInfo = reinterpret_cast<MSLLHOOKSTRUCT*>(lParam);
        const QPoint pos(mouseInfo->pt.x, mouseInfo->pt.y);
        switch (wParam) {
        case WM_LBUTTONUP: {
            emit WinMouseEventPublisher::instance().mouseEvent(GlobalMouseEvent::LButtonUp, pos);
            break;
        }
        case WM_LBUTTONDOWN: {
            emit WinMouseEventPublisher::instance().mouseEvent(GlobalMouseEvent::LButtonDown, pos);
            break;
        }
        case WM_RBUTTONUP: {
            emit WinMouseEventPublisher::instance().mouseEvent(GlobalMouseEvent::RButtonUp, pos);
            break;
        }
        case WM_RBUTTONDOWN: {
            emit WinMouseEventPublisher::instance().mouseEvent(GlobalMouseEvent::RButtonDown, pos);
            break;
        }
        }
    }
    return CallNextHookEx(getGlobalMouseHook(), nCode, wParam, lParam);
}


WinMouseEventPublisher& WinMouseEventPublisher::instance()
{
    static WinMouseEventPublisher instance;
    return instance;
}

WinMouseEventPublisher::WinMouseEventPublisher(QObject* parent) : QObject(parent)
{
    getGlobalMouseHook() = SetWindowsHookEx(WH_MOUSE_LL, GlobalMouseHookProc, GetModuleHandle(NULL), 0);
}

WinMouseEventPublisher::~WinMouseEventPublisher()
{

}
