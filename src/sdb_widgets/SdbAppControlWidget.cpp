#include "SdbAppControlWidget.h"
#include "SdbRadioButton.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

SdbAppControlWidget::SdbAppControlWidget()
    : QWidget(), rawChartController_(this)
{
    createWidget();
}

void SdbAppControlWidget::createWidget()
{
    chartWindowSettings = jsonConfig_.parseSettings();
    int rowIdx = 0;
    for (auto& windowSettings : chartWindowSettings){
        const auto& windowName = windowSettings->name();
        QGroupBox* windowGroupBox = new QGroupBox(windowName, this);
        auto* groupLayout = new QGridLayout(this);
        auto groupRowIdx = 0;
        windowGroupBox->setCheckable(true);
        windowGroupBox->setEnabled(windowSettings->show());
        for(auto& chartSettings : windowSettings->chartSettingsRef()){
            auto& chartName = chartSettings->name();
            auto*chartGroup = new QGroupBox(chartName);
            chartGroup->setCheckable(true);
            chartGroup->setChecked(chartSettings->enabled());
            auto hbox = new QHBoxLayout;
            auto yActiveIdx = 0;
            auto groupColIdx = 0;
            for(auto& yLabel : chartSettings->yLabels()){
                auto yLabelCheckBox = new QCheckBox(yLabel);
                yLabelCheckBox->setChecked(chartSettings->yActive().at(yActiveIdx++));
                hbox->addWidget(yLabelCheckBox, groupColIdx++);
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

//    rawChartRBtn_ = new QCheckBox("Raw Chart", this);
//    rawChartRBtn_->setChecked(true);
//    QObject::connect(rawChartRBtn_, &QCheckBox::stateChanged, &rawChartController_, &SdbRawChartController::handleRawChartWindow);
//    rawChartRBtn_->setStyleSheet("QCheckBox { padding: 20; color: white };\n QCheckBox::indicator {\n"
//                  "    color: black;\n"
//                  "}");
//    rawChartRBtn_->update();

}
