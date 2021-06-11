/**
 * author: selyunin
 */
#include "SdbAppControlWidget.h"
#include "SdbMainWindow.h"
#include <QDesktopWidget>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>
#include <QtWidgets/QApplication>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SdbMainWindow app_control("IMU Charts");
    SdbAppControlWidget app_control_widget;
    app_control.setCentralWidget(&app_control_widget);
    app_control.resize(250, 400);
    app_control.move(200, 200);

    app_control.show();
    app_control.activateWindow();

    return a.exec();
}