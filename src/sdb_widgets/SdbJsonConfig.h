#ifndef APP_SDBJSONCONFIG_H
#define APP_SDBJSONCONFIG_H

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include "SdbChartWindowSettings.h"
#include "SdbChartSettings.h"

QT_USE_NAMESPACE

class SdbJsonConfig: public QObject
{
    Q_OBJECT

public:
    SdbJsonConfig();
    QVector<SdbChartWindowSettings*> parseSettings();
private:
    QVector<SdbChartWindowSettings*> parseAllChartWindowsConfig(const QJsonArray& allChartConfigs);
    SdbChartWindowSettings* parseChartWindowConfig(const QJsonObject& chartConfig);
    SdbChartSettings* parseChartSettings(const QJsonObject& chartConfig);
    QFileInfo settingsPath_;
    QDir executablePath_;
    QFile jsonSettings_;
    QJsonDocument jsonSettingsDocument_;
};

#endif //APP_SDBJSONCONFIG_H
