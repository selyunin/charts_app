#ifndef APP_SDBSETTINGSCHART_H
#define APP_SDBSETTINGSCHART_H

#include <QObject>
#include <QString>
#include <QVector>
#include <iostream>
#include "SdbSettingsSeries.h"

class SdbSettingsChart : public QObject
{
    Q_OBJECT

public:
    SdbSettingsChart() = default;
    Q_PROPERTY(QString name MEMBER name_ READ name WRITE setName)
    Q_PROPERTY(QString xLabel MEMBER xLabel_ READ xLabel WRITE setXLabel)
    Q_PROPERTY(QString type MEMBER type_ READ type WRITE setType)
    Q_PROPERTY(bool enabled MEMBER enabled_ READ enabled WRITE setEnabled)
    const QString &name() { return name_; }
    void setName(const QString &newName) { name_ = newName; }
    const QString &xLabel() { return xLabel_; }
    void setXLabel(const QString &newXLabel) { xLabel_ = newXLabel; }
    const QString &type() { return type_; }
    void setType(const QString &newType) { type_ = newType; }
    bool enabled() { return enabled_; }

    QVector<SdbSettingsSeries*> seriesSettings;

public Q_SLOTS:
    void setEnabled(bool newValue) { enabled_ = newValue; std::cout<<"Enabled: "<<enabled_<<"\n";}

private:
    QString name_;
    bool enabled_;
    QString xLabel_;
    QString type_;
};

#endif //APP_SDBSETTINGSCHART_H
