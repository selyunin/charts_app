#include <QString>
#include <iostream>
#include "SdbMainWindow.h"

using namespace std;

SdbMainWindow::SdbMainWindow(const QString& title)
{
    resize(800, 600);
    setWindowTitle(title);
    setDarkTheme();
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