#ifndef APP_SDBCHARTSETTINGS_H
#define APP_SDBCHARTSETTINGS_H

#include <QObject>
#include <QString>
#include <QVector>

class SdbChartSettings : public QObject
{
    Q_OBJECT

public:
    SdbChartSettings() = default;
    Q_PROPERTY(QString name MEMBER name_ READ name WRITE setName)
    Q_PROPERTY(int numGraphs MEMBER numGraphs_ READ numGraphs WRITE setNumGraphs)
    Q_PROPERTY(QString xLabel MEMBER xLabel_ READ xLabel WRITE setXLabel)
    Q_PROPERTY(QVector<QString> yLabels MEMBER yLabels_)
    Q_PROPERTY(QString type MEMBER type_ READ type WRITE setType)
    Q_PROPERTY(bool enabled MEMBER enabled_ READ enabled WRITE setEnabled)
    const QString &name() { return name_; }
    void setName(const QString &newName) { name_ = newName; }
    int numGraphs() { return numGraphs_; }
    void setNumGraphs(const int newValue) { numGraphs_ = newValue; }
    const QString &xLabel() { return xLabel_; }
    void setXLabel(const QString &newXLabel) { xLabel_ = newXLabel; }
    QVector<QString> &yLabels() { return yLabels_; }
    void addYLabel(const QString &label) { yLabels_.push_back(label); }
    void clearYLabels() { yLabels_.clear(); }
    const QString &type() { return type_; }
    void setType(const QString &newType) { type_ = newType; }
    bool enabled() { return enabled_; }
    void setEnabled(bool newValue) { enabled_ = newValue; }
    QVector<bool> &yActive() { return yActive_; }
    void addYActive(bool value) { yActive_.push_back(value); }
    void clearYActive() { yActive_.clear(); }

private:
    QString name_;
    bool enabled_;
    int numGraphs_;
    QString xLabel_;
    QVector<QString> yLabels_;
    QVector<bool> yActive_;
    QString type_;
};

#endif //APP_SDBCHARTSETTINGS_H
