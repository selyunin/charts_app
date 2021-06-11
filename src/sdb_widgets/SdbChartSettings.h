#ifndef APP_SDBCHARTSETTINGS_H
#define APP_SDBCHARTSETTINGS_H

#include <QString>
#include <QVector>

class SdbChartSettings
{
public:
    SdbChartSettings(){};
private:
    QString name_;
    int numGraphs_;
    QString xLabel_;
    QVector<QString> yLabels_;
    QString type_;
};

#endif //APP_SDBCHARTSETTINGS_H
