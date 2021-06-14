#ifndef APP_SDBCHARTWIDGET_H
#define APP_SDBCHARTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QPointF>
#include <QChart>
#include <QVector>

#include "SdbChartControlPanel.h"
#include "SdbChartView.h"

class SdbChartWidget : public QWidget{
    Q_OBJECT
public:
    SdbChartWidget() = delete;
    explicit SdbChartWidget(QWidget* parent = nullptr);
    void createWidget();
    void createCharts();

    SdbChartView rawMagChartView;
    SdbChartView rawGyroChartView;
    SdbChartView rawAccelChartView;

    SdbChartView rawMag2ChartView;
    SdbChartView rawGyro2ChartView;
    SdbChartView tempChartView;

    QVector<SdbChartView*> chartViews;

    QGridLayout grid;
    SdbChartControlPanel * chartControls;
};


#endif //APP_SDBCHARTWIDGET_H
