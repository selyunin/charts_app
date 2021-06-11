#include "SdbJsonConfig.h"
#include <QByteArray>
#include <iostream>

SdbJsonConfig::SdbJsonConfig(): QObject()
{
    executablePath.setPath(QDir::currentPath());
    auto jsonSettingsPath = executablePath.absolutePath() + "/settings/settings.json";
    settingsPath.setFile(jsonSettingsPath);
    if (!(settingsPath.exists() && settingsPath.isFile())){
        std::cout<<"JSON `settings.json` file not found, we looked in: "<<
            settingsPath.absolutePath().toUtf8().data()<<"\n";
        std::cout<<"Provide valid `settings.json` in directory: "<<
            settingsPath.absolutePath().toUtf8().data()<<"\n";
        exit(1);
    }
}

void SdbJsonConfig::parseSettings()
{
    jsonSettings.setFileName(settingsPath.absoluteFilePath());
    QByteArray jsonContent;
    if (!jsonSettings.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!jsonSettings.atEnd()) {
        QByteArray line = jsonSettings.readLine();
        jsonContent += line;
    }
    jsonSettingsDocument = QJsonDocument::fromJson(jsonContent);
    std::cout<<"Is object: "<<jsonSettingsDocument.isObject()<<"\n";
}
