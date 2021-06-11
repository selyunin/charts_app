#ifndef APP_SDBCHARTCONTROLS_H
#define APP_SDBCHARTCONTROLS_H

#include <QHBoxLayout>
#include "SdbButton.h"

class SdbChartControls : public QHBoxLayout {
    Q_OBJECT
public slots:
    void startButtonHandler();
    void stopButtonHandler();
    void saveButtonHandler();
    void recordButtonHandler();
public:
    explicit SdbChartControls(QWidget* parent);
    void createControls();

private:
    SdbButton* startButton_;
    SdbButton* stopButton_;
    SdbButton* recordButton_;
    SdbButton* saveHwConfig_;
    int startIdx_;
    int stopIdx_;
    int recordIdx_;
    int saveHwIdx_;
};


#endif //APP_SDBCHARTCONTROLS_H
