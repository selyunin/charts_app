#include "SdbAppControlWidget.h"
#include "SdbRadioButton.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "SdbChartSettings.h"

SdbAppControlWidget::SdbAppControlWidget()
    : QWidget()
{
    createWidget();
}

void SdbAppControlWidget::createWidget()
{
    chartWindowSettings = jsonConfig_.parseSettings();
    int rowIdx = 0;
    for (auto windowSettings : chartWindowSettings){
        const auto& windowName = windowSettings->name();
        QGroupBox* windowGroupBox = new QGroupBox(windowName, this);
        auto* groupLayout = new QGridLayout(this);
        auto groupRowIdx = 0;
        QObject::connect(windowGroupBox, &QGroupBox::clicked, windowSettings, &SdbChartWindowSettings::setShow);
        windowGroupBox->setCheckable(true);
        windowGroupBox->setEnabled(true);
        windowGroupBox->setChecked(windowSettings->show());

        for(auto& chartSettings : windowSettings->chartSettingsRef()){
            auto& chartName = chartSettings->name();
            auto*chartGroup = new QGroupBox(chartName);
            chartGroup->setCheckable(true);
            chartGroup->setEnabled(true);
            chartGroup->setChecked(chartSettings->enabled());
            QObject::connect(chartGroup, &QGroupBox::clicked, chartSettings, &SdbChartSettings::setEnabled);
            auto hbox = new QHBoxLayout;
            auto yActiveIdx = 0;
            for(auto& yLabel : chartSettings->yLabels()){
                auto yLabelCheckBox = new QCheckBox(yLabel);
                yLabelCheckBox->setChecked(chartSettings->yActive().at(yActiveIdx++));
                //connect checkboxes of individual elements to a signal
//                QObject::connect(yLabelCheckBox, &QCheckBox::stateChanged, )
                hbox->addWidget(yLabelCheckBox);
            }
            chartGroup->setLayout(hbox);
            groupLayout->addWidget(chartGroup, groupRowIdx++, 0);
            groupRowIdx++;
        }
        windowGroupBox->setLayout(groupLayout);
        grid_.addWidget(windowGroupBox, rowIdx++, 0);
    }
    setLayout(&grid_);
    setWindowTitle("Charts");

//    QObject::connect(rawChartRBtn_, &QCheckBox::stateChanged, &rawChartController_, &SdbChartController::handleRawChartWindow);

}
