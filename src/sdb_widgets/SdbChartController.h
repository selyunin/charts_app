#ifndef APP_SDBCHARTCONTROLLER_H
#define APP_SDBCHARTCONTROLLER_H

#include "SdbChartWidget.h"
#include "SdbMainWindow.h"
#include <memory>
#include <QObject>

QT_USE_NAMESPACE

class SdbChartController : public QObject
{
    Q_OBJECT

    void createRawChartWindow(QWidget* parent);
    void destroyRawChartWindow() const;
public slots:
    void handleRawChartWindow(int state);

public:
    SdbChartController(QObject* parent);

    SdbMainWindow* pChartWindow;
    SdbChartWidget* pChartWidget;
};

#endif //APP_SDBCHARTCONTROLLER_H
