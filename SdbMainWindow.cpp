#include <QString>
#include <iostream>
#include "SdbMainWindow.h"

using namespace std;

SdbMainWindow::SdbMainWindow(const std::string& title, const QApplication* app)
{
    this->resize(800, 600);
    this->setWindowTitle(QString(title.c_str()));
    this->ptr_app = app;
}

void SdbMainWindow::keyPressEvent(QKeyEvent* event)
{
    auto key_pressed = event->key();
    if (key_pressed == 'Q'){
        if (this->ptr_app){
            QApplication::quit();
        }
    }
}