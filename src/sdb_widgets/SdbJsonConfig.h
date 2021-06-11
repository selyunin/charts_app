#ifndef APP_SDBJSONCONFIG_H
#define APP_SDBJSONCONFIG_H

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QObject>

QT_USE_NAMESPACE

class SdbJsonConfig: public QObject
{
    Q_OBJECT

public:
    SdbJsonConfig();

    void parseSettings();
    QFileInfo settingsPath;
    QDir executablePath;
    QFile jsonSettings;
    QJsonDocument jsonSettingsDocument;
};

#endif //APP_SDBJSONCONFIG_H
