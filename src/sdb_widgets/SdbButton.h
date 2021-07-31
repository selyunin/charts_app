#ifndef APP_SDBBUTTON_H
#define APP_SDBBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>

class SdbButton : public QPushButton {
public:
    SdbButton(const QString& text, const QColor& backgroundColor, QWidget* parent = nullptr);

};

#endif //APP_SDBBUTTON_H
