#ifndef APP_SDBCHARTWIDGET_H
#define APP_SDBCHARTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QPointF>
#include <QChart>
#include <QVector>

#include "SdbChartControlPanel.h"
#include "SdbChartView.h"
#include "SdbSettingsChartWindow.h"

class SdbChartWidget : public QWidget{
    Q_OBJECT
public:
    SdbChartWidget() = delete;
    explicit SdbChartWidget(QWidget* parent = nullptr);
    void populateCharts(SdbSettingsChartWindow* windowSettings);

    QVector<SdbChartView*> chartViews;

    QGridLayout grid;
    SdbChartControlPanel * chartControls;

    int num_rows;
    int num_cols;
    int current_row;
    int current_col;
};


#endif //APP_SDBCHARTWIDGET_H
