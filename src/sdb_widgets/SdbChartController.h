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

    void createRawChartWindow(QWidget* parent);
    void destroyRawChartWindow() const;
public slots:
    void handleRawChartWindow(int state);

public:
    SdbChartController(QObject* parent);

    void createChartWindow(SdbSettingsChartWindow* settings);

    SdbMainWindow* pChartWindow;
    SdbChartWidget* pChartWidget;

    QVector<SdbMainWindow*> pChartWindows;
    QVector<SdbChartWidget*> pChartWidgets;
};

#endif //APP_SDBCHARTCONTROLLER_H
