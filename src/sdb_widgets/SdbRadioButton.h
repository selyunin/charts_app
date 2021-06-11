#ifndef APP_SDBRADIOBUTTON_H
#define APP_SDBRADIOBUTTON_H

#include <QRadioButton>

class SdbRadioButton : public QRadioButton
{
public:
    explicit SdbRadioButton(const QString& text, QWidget* parent);
};

#endif //APP_SDBRADIOBUTTON_H
