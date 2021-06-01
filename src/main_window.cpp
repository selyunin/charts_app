#include <QString>
#include <iostream>
#include "main_window.h"

using namespace std;

main_window::main_window(const std::string& title, const QApplication* app)
{
    this->resize(800, 600);
    this->setWindowTitle(QString(title.c_str()));
    this->ptr_app = app;
}

void main_window::keyPressEvent(QKeyEvent* event)
{
    auto key_pressed = event->key();
    if (key_pressed == 'Q'){
        if (this->ptr_app){
            QApplication::quit();
        }
    }
}