#pragma once

#include <QWidget>

#include <memory>
#include "GlobalMouseEvent.h"
#include <QPoint>

namespace Ui { class WorkWindow; }

class WorkWindow : public QWidget {
    Q_OBJECT

public:
    explicit WorkWindow(QWidget* parent = nullptr);

    ~WorkWindow() override;
private slots:
    void handleGlobalMouseEvent(GlobalMouseEvent event, QPoint globalPos);
private:
    std::unique_ptr<Ui::WorkWindow> ui = nullptr;

};
