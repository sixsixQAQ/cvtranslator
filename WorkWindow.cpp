#include "WorkWindow.h"
#include "ui_WorkWindow.h"

#include "WinMouseEventPublisher.h"
#include <windows.h>
#include <QDebug>
#include <QClipboard>
#include <QTimer>

WorkWindow::WorkWindow(QWidget* parent) :
    QWidget(parent), ui(std::make_unique<Ui::WorkWindow>())
{
    ui->setupUi(this);

    connect(&WinMouseEventPublisher::instance(), &WinMouseEventPublisher::mouseEvent, this, &WorkWindow::handleGlobalMouseEvent);
}


WorkWindow::~WorkWindow() {
}

void simulatCtrlC()
{
    SHORT ctrlState = GetAsyncKeyState(VK_CONTROL);
    SHORT shiftState = GetAsyncKeyState(VK_SHIFT);
    SHORT altState = GetAsyncKeyState(VK_MENU);

    qDebug() << "ctrlState:" << (ctrlState & 0x8000);
    qDebug() << "shiftState:" << (shiftState & 0x8000);
    qDebug() << "altState:" << (altState & 0x8000);
    qDebug() << "----------------------------";


    //INPUT inputs[4] = {};
    //ZeroMemory(inputs, sizeof(inputs));

    //inputs[0].type = INPUT_KEYBOARD;
    //inputs[0].ki.wVk = VK_CONTROL;

    //inputs[1].type = INPUT_KEYBOARD;
    //inputs[1].ki.wVk = 'C';

    //inputs[2].type = INPUT_KEYBOARD;
    //inputs[2].ki.wVk = 'C';
    //inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    //inputs[3].type = INPUT_KEYBOARD;
    //inputs[3].ki.wVk = VK_CONTROL;
    //inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    //UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));




    //if (uSent != ARRAYSIZE(inputs))
    //{
    //    qDebug() << "SendInput failed:" << HRESULT_FROM_WIN32(GetLastError());
    //}
}

void WorkWindow::handleGlobalMouseEvent(GlobalMouseEvent event, QPoint globalPos)
{
    switch (event)
    {
    case GlobalMouseEvent::LButtonUp: {
        //QTimer::singleShot(0, this, []() {
        simulatCtrlC();
        //});
        break;
    }
    case GlobalMouseEvent::LButtonDown:
        POINT globalPos;
        GetCursorPos(&globalPos);
        HWND hwnd = WindowFromPoint(globalPos);
        if (hwnd) {
            std::wstring title(4096, L'\0');
            qDebug() << 
        }
        simulatCtrlC();
        break;
    }
}
