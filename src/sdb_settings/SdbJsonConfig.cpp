#include <QByteArray>
#include <QVector>
#include <iostream>
#include "SdbJsonConfig.h"
#include "SdbSettingsChartWindow2D.h"

SdbJsonConfig::SdbJsonConfig(): QObject()
{
    executablePath_.setPath(QDir::currentPath());
    auto jsonSettingsPath = executablePath_.absolutePath() + "/settings/settings.json";
    settingsPath_.setFile(jsonSettingsPath);
    if (!(settingsPath_.exists() && settingsPath_.isFile())){
        std::cout<<"JSON `settings.json` file not found, we looked in: "<< settingsPath_.absolutePath().toUtf8().data()<<"\n";
        std::cout<<"Provide valid `settings.json` in directory: "<< settingsPath_.absolutePath().toUtf8().data()<<"\n";
        exit(1);
    }
}

QVector<SdbSettingsChartWindow*> SdbJsonConfig::parseSettings()
{
    QVector<SdbSettingsChartWindow*> settings;
    jsonSettings_.setFileName(settingsPath_.absoluteFilePath());
    if (!jsonSettings_.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout<<"Cannot open `settings.json` file!\n";
        return settings;
    }

    QByteArray jsonContent = jsonSettings_.readAll();
    jsonSettingsDocument_ = QJsonDocument::fromJson(jsonContent);
    if (jsonSettingsDocument_.isNull()){
        std::cout<<"`settings.json` is not a valid JSON!\n";
    }

    if (jsonSettingsDocument_.isObject()){
        auto obj = jsonSettingsDocument_.object();

        if(obj.contains("ChartWindows") && obj["ChartWindows"].isArray()){
            settings = parseAllChartWindowsConfig(obj["ChartWindows"].toArray());
        }
    }
    return settings;
}

QVector<SdbSettingsChartWindow*> SdbJsonConfig::parseAllChartWindowsConfig(const QJsonArray& windowConfigs)
{
    QVector<SdbSettingsChartWindow*> parsedWindowConfigs;
    std::cout<<"SdbJsonConfig::parseAllChartWindowsConfig\n";
    for (auto windowConfig=windowConfigs.begin(); windowConfig != windowConfigs.end(); ++windowConfig){
        if (windowConfig->isObject()){
            auto parsedWindowConfig = parseChartWindowConfig(windowConfig->toObject());
            parsedWindowConfigs.push_back(parsedWindowConfig);
        }
    }
    return parsedWindowConfigs;
}
SdbSettingsChartWindow* SdbJsonConfig::parseChartWindowConfig2D(const QJsonObject& chartConfigObject)
{
    std::cout<<"SdbJsonConfig::parseChartWindowConfig\n";
    auto* windowSettings = new SdbSettingsChartWindow2D();
    if (chartConfigObject.contains("name") && chartConfigObject["name"].isString()){
        windowSettings->setName(chartConfigObject["name"].toString());
    }
    if (chartConfigObject.contains("show") && chartConfigObject["show"].isBool()){
        windowSettings->setShow(chartConfigObject["show"].toBool());
    }
    if (chartConfigObject.contains("type")){
        windowSettings->setType(chartConfigObject["type"].toString());
    }
    if (chartConfigObject.contains("num_charts")){
        windowSettings->setNumCharts(chartConfigObject["num_charts"].toInt());
    }
    if (chartConfigObject.contains("num_rows")){
        windowSettings->setNumRows(chartConfigObject["num_rows"].toInt());
    }
    if (chartConfigObject.contains("num_cols")){
        windowSettings->setNumCols(chartConfigObject["num_cols"].toInt());
    }
    if (chartConfigObject.contains("charts") && chartConfigObject["charts"].isArray()){
        auto chartConfigArray = chartConfigObject["charts"].toArray();
        for (auto elem = chartConfigArray.begin(); elem != chartConfigArray.end(); ++elem){
            auto chartConfig = parseChartSettings(elem->toObject());
            windowSettings->chartSettingsRef().push_back(chartConfig);
        }
    }
    return windowSettings;
}


SdbSettingsChartWindow* SdbJsonConfig::parseChartWindowConfig(const QJsonObject& chartConfigObject)
{
    if (chartConfigObject.contains("type") && chartConfigObject["type"].isString()){
        QString type = chartConfigObject["type"].toString();
        if (type == QString("2D")){
            return parseChartWindowConfig2D(chartConfigObject);
        }
    }
    return nullptr;
}

SdbSettingsChart* SdbJsonConfig::parseChartSettings(const QJsonObject& chartConfig)
{
    auto* chartSettings = new SdbSettingsChart();
    if (chartConfig.contains("name") && chartConfig["name"].isString()){
        chartSettings->setName(chartConfig["name"].toString());
    }
    if (chartConfig.contains("enabled") && chartConfig["enabled"].isBool()){
        chartSettings->setEnabled(chartConfig["enabled"].toBool());
    }
    if (chartConfig.contains("x_label") && chartConfig["x_label"].isString()){
        chartSettings->setXLabel(chartConfig["x_label"].toString());
    }
    if (chartConfig.contains("series") && chartConfig["series"].isArray()){
        auto chartConfigArray = chartConfig["series"].toArray();
        for (auto elem = chartConfigArray.begin(); elem != chartConfigArray.end(); ++elem){
            auto seriesConfig = parseSeriesSettings(elem->toObject());
            chartSettings->seriesSettings.push_back(seriesConfig);
        }
    }
    return chartSettings;
}

SdbSettingsSeries* SdbJsonConfig::parseSeriesSettings(const QJsonObject& seriesConfig)
{
    auto* seriesSettings = new SdbSettingsSeries();
    if (seriesConfig.contains("y_label") && seriesConfig["y_label"].isString()){
        seriesSettings->yLabel = seriesConfig["y_label"].toString();
    }
    if (seriesConfig.contains("enabled") && seriesConfig["enabled"].isBool()){
        seriesSettings->enabled = seriesConfig["enabled"].toBool();
    }
    return seriesSettings;
}

void SdbJsonConfig::saveSettings(const QVector<SdbSettingsChartWindow*>& settings, const QString& fileName)
{
    std::cout<<"SdbJsonConfig::saveSettings\n";
    auto jsonSettingsPath = executablePath_.absolutePath() + "/settings/updated_settings.json";
    QFileInfo updatedPath;
    updatedPath.setFile(jsonSettingsPath);
    QFile updatedSettings;
    updatedSettings.setFileName(updatedPath.absoluteFilePath());
    if (!updatedSettings.open(QIODevice::WriteOnly | QIODevice::Text)){
        std::cout<<"Error: cannot open `updated_settings.json` file!\n";

    }
}