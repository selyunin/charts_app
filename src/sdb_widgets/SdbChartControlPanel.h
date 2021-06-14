#ifndef APP_SDBCHARTCONTROLPANEL_H
#define APP_SDBCHARTCONTROLPANEL_H

#include <QHBoxLayout>
#include "SdbButton.h"

class SdbChartControlPanel : public QHBoxLayout {
    Q_OBJECT
public slots:
    void startButtonHandler();
    void stopButtonHandler();
    void saveButtonHandler();
    void recordButtonHandler();
public:
    explicit SdbChartControlPanel(QWidget* parent);
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


#endif //APP_SDBCHARTCONTROLPANEL_H
