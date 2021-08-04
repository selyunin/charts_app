#ifndef APP_SDBSETTINGSCHARTWINDOW_H
#define APP_SDBSETTINGSCHARTWINDOW_H

#include "SdbSettingsChart.h"
#include <QObject>
#include <QVector>
#include <iostream>

class SdbSettingsChartWindow : public QObject
{
    Q_OBJECT

public:
    SdbSettingsChartWindow() = default;
    Q_PROPERTY(QString name MEMBER name_ READ name WRITE setName)
    Q_PROPERTY(bool show MEMBER show_ READ show WRITE setShow)
    Q_PROPERTY(QString type MEMBER type_ READ type WRITE setType)
    QString& name() { return name_; }
    void setName(const QString &newName) { name_ = newName; }
    [[nodiscard]] bool show() const { return show_; }
    void setType(const QString &newType) { type_ = newType; }
    [[nodiscard]] QString& type() { return type_; }

    QVector<SdbSettingsChart*>& chartSettingsRef() { return chartSettings_; }
Q_SIGNALS:
    void showEmit(bool newValue);
public Q_SLOTS:
    void setShow(bool newShowValue) { show_ = newShowValue; emit showEmit(newShowValue); std::cout<<"show: "<<show_<<"\n";}

private:
    QString name_;
    bool show_;
    QString type_;
    QVector<SdbSettingsChart*> chartSettings_;
};

#endif //APP_SDBSETTINGSCHARTWINDOW_H
