#ifndef APP_SDBCHART_H
#define APP_SDBCHART_H

#include <QVector>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

class SdbChart : public QChart
{
    Q_OBJECT
public:
    SdbChart();
    SdbChart(int nCharts, const QString &title, const QVector<QString> &legends);

private:
    int numCharts_;
    QVector<QLineSeries *> series_;
    QVector<QString> seriesLegends_;
    QString title_;
};

#endif //APP_SDBCHART_H
