#include "SdbButton.h"

SdbButton::SdbButton(const QString& text, const QColor& backgroundColor, QWidget* parent):
        QPushButton(parent)
{
    setText(text);
    char hex_string[20];
    sprintf(hex_string, "%X", backgroundColor.rgb());
    QString format = "QPushButton {background-color: #" + QString(hex_string) + "; color: white;}";
    setStyleSheet(format);
    update();
}

QSize SdbButton::sizeHint() const
{
    auto size = QPushButton::sizeHint();
    size.setHeight(size.height() + 10);
    size.setWidth(size.width() * 0.3);
    return size;
}