#include "SdbChartController.h"

#include <iostream>

SdbChartController::SdbChartController(QObject* parent):
    QObject(parent)
{

}
SdbMainWindow* SdbChartController::createChartWindow(SdbSettingsChartWindow* windowSettings)
{
    std::cout<<"SdbChartController::createChartWindow\n";
    auto windowTitle = windowSettings->name();
    auto chartWindow = new SdbMainWindow(windowTitle);
    auto chartWidget = new SdbChartWidget(nullptr);
    chartWindow->setCentralWidget(chartWidget);
    chartWindow->move(520, 200);
    if (windowSettings->type() == QString("2D")){
        chartWidget->populateCharts(dynamic_cast<SdbSettingsChartWindow2D *>(windowSettings));
        // todo: windowSettings->populateCharts();
    }
    return chartWindow;
}