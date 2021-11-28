#ifndef APP_SDBJSONCONFIG_H
#define APP_SDBJSONCONFIG_H

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include "SdbSettingsChartWindow.h"
#include "SdbSettingsChart.h"
#include "SdbSettingsSeries.h"

QT_USE_NAMESPACE

class SdbJsonConfig: public QObject
{
    Q_OBJECT

public:
    SdbJsonConfig();
    QVector<SdbSettingsChartWindow*> parseSettings();
    void saveSettings(const QVector<SdbSettingsChartWindow*>& settings, const QString& fileName = "");
private:
    QVector<SdbSettingsChartWindow*> parseAllChartWindowsConfig(const QJsonArray& allChartConfigs);
    SdbSettingsChartWindow* parseChartWindowConfig(const QJsonObject& chartConfig);
    SdbSettingsChartWindow* parseChartWindowConfig2D(const QJsonObject& chartConfig);
    SdbSettingsChartWindow* parseChartWindowConfig3D(const QJsonObject& chartConfig);
    SdbSettingsChart* parseChartSettings(const QJsonObject& chartConfig);
    SdbSettingsSeries* parseSeriesSettings(const QJsonObject& seriesConfig);
    QFileInfo settingsPath_;
    QDir executablePath_;
    QFile jsonSettings_;
    QJsonDocument jsonSettingsDocument_;
};

#endif //APP_SDBJSONCONFIG_H
