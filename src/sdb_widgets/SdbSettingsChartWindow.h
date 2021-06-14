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
    Q_PROPERTY(int numCharts MEMBER numCharts_ READ numCharts WRITE setNumCharts)
    Q_PROPERTY(int numRows MEMBER numRows_ READ numRows WRITE setNumRows)
    Q_PROPERTY(int numCols MEMBER numCols_ READ numCols WRITE setNumCols)
    QString name() { return name_; }
    void setName(const QString &newName) { name_ = newName; }
    [[nodiscard]] bool show() const { return show_; }

    [[nodiscard]] int numCharts() const { return numCharts_; }
    void setNumCharts(int newValue) { numCharts_ = newValue; }
    [[nodiscard]] int numRows() const { return numRows_; }
    void setNumRows(int newValue) { numRows_ = newValue; }
    [[nodiscard]] int numCols() const { return numCols_; }
    void setNumCols(int newValue) { numCols_ = newValue; }
    QVector<SdbSettingsChart*>& chartSettingsRef() { return chartSettings_; }

public Q_SLOTS:
    void setShow(bool newShowValue) { show_ = newShowValue; std::cout<<"New Value: "<<show_<<"\n";}

private:
    QString name_;
    bool show_;
    int numCharts_;
    int numRows_;
    int numCols_;
    QVector<SdbSettingsChart*> chartSettings_;
};

#endif //APP_SDBSETTINGSCHARTWINDOW_H
