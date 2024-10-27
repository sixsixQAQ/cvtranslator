
#pragma once

#include <QObject>
#include <QPoint>
#include "GlobalMouseEvent.h"
class WinMouseEventPublisher : public QObject {
    Q_OBJECT

public:

    static WinMouseEventPublisher& instance();

Q_SIGNALS:
    void mouseEvent(GlobalMouseEvent event, QPoint pos);
private:
    WinMouseEventPublisher(QObject* parent = nullptr);
    ~WinMouseEventPublisher();
    WinMouseEventPublisher(const WinMouseEventPublisher&) = delete;
    WinMouseEventPublisher& operator=(const WinMouseEventPublisher&) = delete;
};


