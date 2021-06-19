#include "SdbChartController.h"

#include <iostream>

SdbChartController::SdbChartController(QObject* parent):
    QObject(parent)
{

}

void SdbChartController::handleRawChartWindow(int state)
{
    std::cout<<"SdbChartController::handleRawChartWindow = "<<state<<"\n";
    if (state){
        createRawChartWindow(nullptr);
    } else{
        destroyRawChartWindow();
    }
}

void SdbChartController::createRawChartWindow(QWidget *parent)
{
    std::cout<<"SdbChartController::createRawChartWindow\n";
    pChartWindow = new SdbMainWindow("Raw charts");
    pChartWidget = new SdbChartWidget(nullptr);
    pChartWindow->setCentralWidget(pChartWidget);
    pChartWindow->move(470, 200);
    pChartWindow->show();
}

void SdbChartController::destroyRawChartWindow() const
{
    std::cout<<"SdbChartController::destroyRawChartWindow\n";
    pChartWindow->close();
}