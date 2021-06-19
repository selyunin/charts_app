#ifndef APP_SDBSETTINGSSERIES_H
#define APP_SDBSETTINGSSERIES_H

#include <QObject>
#include <QString>
#include <iostream>

class SdbSettingsSeries: public QObject {
    Q_OBJECT

public Q_SLOTS:
    void updateEnabled(bool newValue) {enabled = newValue;std::cout<<yLabel.toUtf8().data()<<": "<<enabled<<"\n"; }
public:
    SdbSettingsSeries() = default;
    Q_PROPERTY(QString yLabel MEMBER yLabel)
    Q_PROPERTY(bool enabled MEMBER enabled)
    QString yLabel;
    bool enabled;
};


#endif //APP_SDBSETTINGSSERIES_H
