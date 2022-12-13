#ifndef APP_SDBCHARTCONTROLLER_H
#define APP_SDBCHARTCONTROLLER_H

#include "SdbChartWidget.h"
#include "SdbMainWindow.h"
#include "SdbSettingsChartWindow.h"
#include <memory>
#include <QObject>

QT_USE_NAMESPACE

class SdbChartController : public QObject
{
    Q_OBJECT

public:
    SdbChartController(QObject* parent);

    SdbMainWindow* createChartWindow(SdbSettingsChartWindow* settings);
};

#endif //APP_SDBCHARTCONTROLLER_H
