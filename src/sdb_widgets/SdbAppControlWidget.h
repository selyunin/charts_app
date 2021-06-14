#ifndef APP_SDBAPPCONTROLWIDGET_H
#define APP_SDBAPPCONTROLWIDGET_H

#include "SdbChartController.h"
#include "SdbChartWindowSettings.h"
#include "SdbJsonConfig.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QGridLayout>
#include <QRadioButton>
#include <QVector>
#include <QWidget>

class SdbAppControlWidget : public QWidget {
    Q_OBJECT
public:
    SdbAppControlWidget();
    void createWidget();

private:
    QGridLayout grid_;
    SdbJsonConfig jsonConfig_;
    QVector<SdbChartController*> chartControllers_;
    QVector<SdbChartWindowSettings*> chartWindowSettings;
};

#endif //APP_SDBAPPCONTROLWIDGET_H
