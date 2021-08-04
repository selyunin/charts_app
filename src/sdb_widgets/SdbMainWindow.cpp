#include <QString>
#include <iostream>
#include "SdbMainWindow.h"

using namespace std;

SdbMainWindow::SdbMainWindow(const QString& title)
{
    setWindowTitle(title);
    everUpdated = false;
}

void SdbMainWindow::keyPressEvent(QKeyEvent* event)
{
    auto key_pressed = event->key();
    if (key_pressed == 'Q'){
        QApplication::quit();
    }
}

void SdbMainWindow::handleShow(int showValue){
    if (showValue){
        if (everUpdated){
            setGeometry(windowPosition);
        }
        everUpdated = true;
        show();
    }
    else{
        windowPosition = geometry();
        hide();
    }
}