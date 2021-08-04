#include "SdbAppControlWidget.h"
#include "SdbRadioButton.h"
#include "sdb_settings/SdbSettingsChart.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>

SdbAppControlWidget::SdbAppControlWidget()
    : QWidget()
{
    chartController_ = new SdbChartController(this);
    parseJsonSettings();
//    createControlWidget();
    createTabControls();
    populateCharts();
}
SdbAppControlWidget::~SdbAppControlWidget(){
    jsonConfig_.saveSettings(chartWindowSettings);
}

void SdbAppControlWidget::parseJsonSettings()
{
    chartWindowSettings = jsonConfig_.parseSettings();
}

void SdbAppControlWidget::createTabControls()
{
    int rowIdx = 0;
    auto tabWidget = new QTabWidget(this);
//    tabWidget->setStyleSheet("QTabWidget {color: #d6d6d6; background-color: #222222; };\
//                                         QTabWidget::tab:selected {color: #d6d6d6; background-color: #222222; }");
//    tabWidget->setStyleSheet("QTabWidget::tab {}");
//    palette.setColor(QPalette::Window, QColor(0x121218));
//    palette.setColor(QPalette::WindowText, QColor(0xd6d6d6));
//    tabWidget->setPalette(palette);

    for (auto* windowSettings : chartWindowSettings){
        auto* controlWidget = createTabControlWidget(windowSettings);
        auto palette = controlWidget->palette();
        palette.setColor(QPalette::Window, QColor(0x121218));
        palette.setColor(QPalette::WindowText, QColor(0xd6d6d6));
        controlWidget->setPalette(palette);
        tabWidget->addTab(controlWidget, windowSettings->name());

    }

    grid_.addWidget(tabWidget, 0, 0);
    setLayout(&grid_);
    setWindowTitle("Charts");
}

QWidget* SdbAppControlWidget::createTabControlWidget(SdbSettingsChartWindow* windowSettings)
{
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
    return windowGroupBox;
}


void SdbAppControlWidget::createControlWidget()
{
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
void SdbAppControlWidget::populateCharts()
{
    for (auto windowSettings : chartWindowSettings) {
        auto createdWindowPtr = chartController_->createChartWindow(windowSettings);
        QObject::connect(windowSettings, &SdbSettingsChartWindow::showEmit, createdWindowPtr, &SdbMainWindow::handleShow);
        if (windowSettings->show()) {
            createdWindowPtr->handleShow(1);
        }
        for (auto& charSettings : windowSettings->chartSettingsRef()){

        }
    }
}
