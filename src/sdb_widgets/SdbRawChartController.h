#ifndef APP_SDBRAWCHARTCONTROLLER_H
#define APP_SDBRAWCHARTCONTROLLER_H

#include <QObject>
#include "SdbRawChartWidget.h"
#include "SdbMainWindow.h"
#include "SdbRawChartWidget.h"
#include <memory>

QT_USE_NAMESPACE

class SdbRawChartController: public QObject
{
    Q_OBJECT

    void createRawChartWindow(QWidget* parent);
    void destroyRawChartWindow() const;
public slots:
    void handleRawChartWindow(int state);

public:
    SdbRawChartController(QObject* parent);

    SdbMainWindow* pRawChartWindow;
    SdbRawChartWidget* pRawChartWidget;
};

#endif //APP_SDBRAWCHARTCONTROLLER_H
