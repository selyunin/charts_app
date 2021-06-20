#include "SdbChartWidget.h"
#include "SdbChart.h"
#include <QString>

SdbChartWidget::SdbChartWidget(QWidget* parent):
        QWidget(parent), grid(this)
{
    chartControls = new SdbChartControlPanel(nullptr);
    chartControls->createControls();
}

void SdbChartWidget::populateCharts(SdbSettingsChartWindow* windowSettings)
{
    num_rows = windowSettings->numRows();
    num_cols = windowSettings->numCols();
    current_row = 1; //! row 0 holds the controls
    current_col = 0;
    grid.addLayout(chartControls, 0, 0,1, num_cols);
    for(auto& chartSetting : windowSettings->chartSettingsRef()){
        auto seriesSettings = chartSetting->seriesSettings;
        auto numCharts = seriesSettings.size();
        auto chartName = chartSetting->name();
        QVector<QString> legends;
        for (auto seriesSetting: seriesSettings){
            legends.push_back(seriesSetting->yLabel);
        }
        auto chart = new SdbChart(numCharts, chartName, legends);
        auto chartView = new SdbChartView();
        chartView->setChart(chart);
        chartViews.push_back(chartView);
        grid.addWidget(chartView, current_row, current_col++, 1, 1);
        if (current_col == num_cols){
            current_col = 0;
            current_row++;
        }
    }
}