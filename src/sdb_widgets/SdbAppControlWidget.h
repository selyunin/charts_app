#ifndef APP_SDBAPPCONTROLWIDGET_H
#define APP_SDBAPPCONTROLWIDGET_H

#include "SdbChartController.h"
#include "sdb_settings/SdbJsonConfig.h"
#include "sdb_settings/SdbSettingsChartWindow.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QGridLayout>
#include <QRadioButton>
#include <QVector>
#include <QWidget>

class SdbAppControlWidget : public QWidget {
    Q_OBJECT
public:
    SdbAppControlWidget();
    ~SdbAppControlWidget() override;
    void createTabControls();
    QWidget* createTabControlWidget(SdbSettingsChartWindow* windowSetting);
    void parseJsonSettings();
    void populateCharts();

private:
    QGridLayout grid_;
    SdbJsonConfig jsonConfig_;
    SdbChartController* chartController_;
    QVector<SdbSettingsChartWindow*> chartWindowSettings;
};

#endif //APP_SDBAPPCONTROLWIDGET_H
