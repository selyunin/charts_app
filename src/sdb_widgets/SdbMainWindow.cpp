#include <QString>
#include <iostream>
#include "SdbMainWindow.h"

using namespace std;

SdbMainWindow::SdbMainWindow(const QString& title)
{
    setWindowTitle(title);
    setDarkTheme();
    everUpdated = false;
}

void SdbMainWindow::keyPressEvent(QKeyEvent* event)
{
    auto key_pressed = event->key();
    if (key_pressed == 'Q'){
        QApplication::quit();
    }
}

void SdbMainWindow::setDarkTheme()
{
    auto palette = QMainWindow::palette();
    palette.setColor(QPalette::Window, QColor(0x121218));
    palette.setColor(QPalette::WindowText, QColor(0xd6d6d6));
    setPalette(palette);
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