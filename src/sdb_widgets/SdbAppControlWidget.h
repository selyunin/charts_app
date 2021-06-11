#ifndef APP_SDBAPPCONTROLWIDGET_H
#define APP_SDBAPPCONTROLWIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QButtonGroup>
#include "SdbRawChartController.h"
#include "SdbJsonConfig.h"

class SdbAppControlWidget : public QWidget {
    Q_OBJECT
public:
    SdbAppControlWidget();
    void createWidget();

private:
    QGridLayout grid_;
    QButtonGroup rawButtonGroup_;
    QCheckBox* rawChartRBtn_;
    QCheckBox* rawMagChart_;
    SdbJsonConfig jsonConfig_;
    SdbRawChartController rawChartController_;
};


#endif //APP_SDBAPPCONTROLWIDGET_H
