#include "SdbRawChartController.h"

#include <iostream>

SdbRawChartController::SdbRawChartController(QObject* parent):
    QObject(parent)
{

}

void SdbRawChartController::handleRawChartWindow(int state)
{
    std::cout<<"SdbRawChartController::handleRawChartWindow = "<<state<<"\n";
    if (state){
        createRawChartWindow(nullptr);
    } else{
        destroyRawChartWindow();
    }
}

void SdbRawChartController::createRawChartWindow(QWidget *parent)
{
    std::cout<<"SdbRawChartController::createRawChartWindow\n";
    pRawChartWindow = new SdbMainWindow("Raw charts");
    pRawChartWidget = new SdbRawChartWidget(nullptr);
    pRawChartWindow->setCentralWidget(pRawChartWidget);
    pRawChartWindow->move(470, 200);
    pRawChartWindow->show();
}

void SdbRawChartController::destroyRawChartWindow() const
{
    std::cout<<"SdbRawChartController::destroyRawChartWindow\n";
    pRawChartWindow->close();
}