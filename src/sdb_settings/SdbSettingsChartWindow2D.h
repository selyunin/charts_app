#ifndef APP_SDBSETTINGSCHARTWINDOW2D_H
#define APP_SDBSETTINGSCHARTWINDOW2D_H

#include <QObject>
#include <QVector>
#include <iostream>
#include "SdbSettingsChartWindow.h"

class SdbSettingsChartWindow2D : public SdbSettingsChartWindow
{
    Q_OBJECT

public:
    SdbSettingsChartWindow2D() = default;
    Q_PROPERTY(int numCharts MEMBER numCharts_ READ numCharts WRITE setNumCharts)
    Q_PROPERTY(int numRows MEMBER numRows_ READ numRows WRITE setNumRows)
    Q_PROPERTY(int numCols MEMBER numCols_ READ numCols WRITE setNumCols)

    [[nodiscard]] int numCharts() const { return numCharts_; }
    void setNumCharts(int newValue) { numCharts_ = newValue; }
    [[nodiscard]] int numRows() const { return numRows_; }
    void setNumRows(int newValue) { numRows_ = newValue; }
    [[nodiscard]] int numCols() const { return numCols_; }
    void setNumCols(int newValue) { numCols_ = newValue; }

private:
    int numCharts_;
    int numRows_;
    int numCols_;
};

#endif //APP_SDBSETTINGSCHARTWINDOW2D_H
