#ifndef APP_SDBRAWCHARTWIDGET_H
#define APP_SDBRAWCHARTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QPointF>
#include <QChart>

#include "SdbChartView.h"
#include "SdbChartControls.h"

class SdbRawChartWidget : public QWidget{
    Q_OBJECT
public:

    SdbRawChartWidget() = delete;
    explicit SdbRawChartWidget(QWidget* parent = nullptr);
    void createWidget();
    void createCharts();

    SdbChartView rawMagChartView;
    SdbChartView rawGyroChartView;
    SdbChartView rawAccelChartView;

    SdbChartView rawMag2ChartView;
    SdbChartView rawGyro2ChartView;
    SdbChartView tempChartView;
    QGridLayout grid;
    SdbChartControls* chartControls;

};


#endif //APP_SDBRAWCHARTWIDGET_H
