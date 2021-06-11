#ifndef APP_SDBCHARTWINDOWSETTINGS_H
#define APP_SDBCHARTWINDOWSETTINGS_H

#include "SdbChartSettings.h"
#include <QVector>

class SdbChartWindowSettings
{
public:
    SdbChartWindowSettings(){};

private:
    QString name_;
    bool show_;
    int numCharts_;
    int numRows_;
    int numCols_;
    QVector<SdbChartSettings> chartSettings_;
};

#endif //APP_SDBCHARTWINDOWSETTINGS_H
