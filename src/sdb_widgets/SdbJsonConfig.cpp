#include "SdbJsonConfig.h"
#include <QByteArray>
#include <QVector>
#include <iostream>

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

QVector<SdbChartWindowSettings*> SdbJsonConfig::parseSettings()
{
    QVector<SdbChartWindowSettings*> settings;
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

QVector<SdbChartWindowSettings*> SdbJsonConfig::parseAllChartWindowsConfig(const QJsonArray& windowConfigs)
{
    QVector<SdbChartWindowSettings*> parsedWindowConfigs;
    std::cout<<"SdbJsonConfig::parseAllChartWindowsConfig\n";
    for (auto windowConfig=windowConfigs.begin(); windowConfig != windowConfigs.end(); ++windowConfig){
        if (windowConfig->isObject()){
            auto parsedWindowConfig = parseChartWindowConfig(windowConfig->toObject());
            parsedWindowConfigs.push_back(parsedWindowConfig);
        }
    }
    return parsedWindowConfigs;
}

SdbChartWindowSettings* SdbJsonConfig::parseChartWindowConfig(const QJsonObject& chartConfigObject)
{
    std::cout<<"SdbJsonConfig::parseChartWindowConfig\n";
    auto* windowSettings = new SdbChartWindowSettings();
    if (chartConfigObject.contains("name") && chartConfigObject["name"].isString()){
        windowSettings->setName(chartConfigObject["name"].toString());
    }
    if (chartConfigObject.contains("show") && chartConfigObject["show"].isBool()){
        windowSettings->setShow(chartConfigObject["show"].toBool());
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

SdbChartSettings* SdbJsonConfig::parseChartSettings(const QJsonObject& chartConfig)
{
    auto* chartSettings = new SdbChartSettings();
    if (chartConfig.contains("name") && chartConfig["name"].isString()){
        chartSettings->setName(chartConfig["name"].toString());
    }
    if (chartConfig.contains("num_graphs")){
        chartSettings->setNumGraphs(chartConfig["num_graphs"].toInt());
    }
    if (chartConfig.contains("enabled") && chartConfig["enabled"].isBool()){
        chartSettings->setEnabled(chartConfig["enabled"].toBool());
    }
    if (chartConfig.contains("x_label") && chartConfig["x_label"].isString()){
        chartSettings->setXLabel(chartConfig["x_label"].toString());
    }
    if (chartConfig.contains("y_labels") && chartConfig["y_labels"].isArray()){
        auto yLabelsArray = chartConfig["y_labels"].toArray();
        for (auto elem = yLabelsArray.begin(); elem != yLabelsArray.end(); ++elem){
            chartSettings->addYLabel(elem->toString());
        }
    }
    if (chartConfig.contains("y_active") && chartConfig["y_active"].isArray()){
        auto yLabelsArray = chartConfig["y_active"].toArray();
        for (auto elem = yLabelsArray.begin(); elem != yLabelsArray.end(); ++elem){
            chartSettings->addYActive(elem->toBool());
        }
    }
    return chartSettings;
}