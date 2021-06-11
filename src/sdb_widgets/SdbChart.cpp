#include "SdbChart.h"


SdbChart::SdbChart():
        QChart()
{
    setTheme(ChartTheme::ChartThemeDark);
}

SdbChart::SdbChart(int nCharts, const QString& chartTitle, const QVector<QString>& legends): numCharts_{nCharts}, title_{chartTitle}, seriesLegends_{legends}
{
    setTheme(ChartTheme::ChartThemeDark);
    setTitle(chartTitle);
    for(int i=0; i< numCharts_; i++){
        QLineSeries* ser = new QLineSeries(this);
        ser->setName(legends[i]);
        series_.push_back(ser);
        addSeries(ser);
    }
    createDefaultAxes();
}