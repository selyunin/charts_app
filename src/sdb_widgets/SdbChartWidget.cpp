#include "SdbChartWidget.h"
#include "SdbChart.h"
#include <QString>

SdbChartWidget::SdbChartWidget(QWidget* parent):
        QWidget(parent), grid(this)
{
    chartControls = new SdbChartControlPanel(nullptr);
    createWidget();
}

void SdbChartWidget::createWidget()
{
    chartControls->createControls();
    grid.addLayout(chartControls, 0, 1,1,2);
    createCharts();

}
void SdbChartWidget::createCharts()
{
    auto magChart = new SdbChart(3, QString("Raw Mag 1"), QVector<QString>{"x", "y", "z"});
    rawMagChartView.setChart(magChart);
    grid.addWidget(&rawMagChartView, 1, 0, 1, 1);

    auto gyroChart = new SdbChart(3, QString("Raw Gyro 1"), QVector<QString>{"x", "y", "z"});
    rawGyroChartView.setChart(gyroChart);
    grid.addWidget(&rawGyroChartView, 1, 1, 1, 1);

    auto accelChart = new SdbChart(3, QString("Raw Accel 1"), QVector<QString>{"x", "y", "z"});
    rawAccelChartView.setChart(accelChart);
    grid.addWidget(&rawAccelChartView, 1, 2, 1, 1);

    auto mag2Chart = new SdbChart(3, QString("Raw Mag 2"), QVector<QString>{"x", "y", "z"});
    rawMag2ChartView.setChart(mag2Chart);
    grid.addWidget(&rawMag2ChartView, 2, 0, 1, 1);

    auto gyro2Chart = new SdbChart(3, QString("Raw Gyro 1"), QVector<QString>{"x", "y", "z"});
    rawGyro2ChartView.setChart(gyro2Chart);
    grid.addWidget(&rawGyro2ChartView, 2, 1, 1, 1);

    auto tempChart = new SdbChart(3, QString("Temperature"), QVector<QString>{"x", "y", "z"});
    tempChartView.setChart(tempChart);
    grid.addWidget(&tempChartView, 2, 2, 1, 1);
}