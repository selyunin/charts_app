#include "SdbAppControlWidget.h"
#include "SdbRadioButton.h"
#include "sdb_settings/SdbSettingsChart.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

SdbAppControlWidget::SdbAppControlWidget()
    : QWidget()
{
    chartController_ = new SdbChartController(this);
    createControlWidget();
}

void SdbAppControlWidget::createControlWidget()
{
    chartWindowSettings = jsonConfig_.parseSettings();
    int rowIdx = 0;
    for (auto windowSettings : chartWindowSettings){
        const auto& windowName = windowSettings->name();
        QGroupBox* windowGroupBox = new QGroupBox(windowName, this);
        auto* groupLayout = new QGridLayout(this);
        auto groupRowIdx = 0;
        QObject::connect(windowGroupBox, &QGroupBox::clicked, windowSettings, &SdbSettingsChartWindow::setShow);
        windowGroupBox->setCheckable(true);
        windowGroupBox->setEnabled(true);
        windowGroupBox->setChecked(windowSettings->show());

        for(auto& chartSettings : windowSettings->chartSettingsRef()){
            auto& chartName = chartSettings->name();
            auto*chartGroup = new QGroupBox(chartName);
            chartGroup->setCheckable(true);
            chartGroup->setEnabled(true);
            chartGroup->setChecked(chartSettings->enabled());
            QObject::connect(chartGroup, &QGroupBox::clicked, chartSettings, &SdbSettingsChart::setEnabled);
            auto hbox = new QHBoxLayout;
            for(auto& seriesSettings : chartSettings->seriesSettings){
                auto yLabelCheckBox = new QCheckBox(seriesSettings->yLabel);
                QObject::connect(yLabelCheckBox, &QCheckBox::stateChanged, seriesSettings, &SdbSettingsSeries::updateEnabled);
                yLabelCheckBox->setChecked(seriesSettings->enabled);
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
}

void SdbAppControlWidget::populateChartWindows()
{
    for(auto chartWindowSetting : chartWindowSettings){
        chartController_->createChartWindow(chartWindowSetting);
    }
}

