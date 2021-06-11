#ifndef APP_SDBCHARTVIEW_H
#define APP_SDBCHARTVIEW_H

#include <QChartView>

QT_CHARTS_USE_NAMESPACE

class SdbChartView : public QChartView {
public:
    SdbChartView(): QChartView() {
        this->setRenderHint(QPainter::Antialiasing, true);
    }
};


#endif //APP_SDBCHARTVIEW_H
