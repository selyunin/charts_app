#include "SdbRadioButton.h"
#include <iostream>

SdbRadioButton::SdbRadioButton(const QString& text, QWidget* parent):
    QRadioButton(text, parent)
{
    setStyleSheet("QRadioButton { padding: 20; color: white};\n QRadioButton::indicator::checked {\n"
                  "    color: black;\n"
                  "}");
    auto ss = styleSheet();
    std::cout<<"Stylesheet: "<<ss.toUtf8().constData()<<"\n";
}
