#include "SdbChartControlPanel.h"
#include "SdbButton.h"
#include <iostream>

void SdbChartControlPanel::startButtonHandler()
{
    std::cout<<"Start button clicked: "<< startIdx_++<<std::endl;
}

void SdbChartControlPanel::stopButtonHandler()
{
    std::cout<<"Stop button clicked: "<< stopIdx_++<<std::endl;
}

void SdbChartControlPanel::recordButtonHandler()
{
    std::cout<<"Record button clicked: "<< recordIdx_++<<std::endl;
}

void SdbChartControlPanel::saveButtonHandler()
{
    std::cout<<"Save button clicked: "<< saveHwIdx_++<<std::endl;
}

SdbChartControlPanel::SdbChartControlPanel(QWidget* parent):
        QHBoxLayout(parent), startIdx_{0}, stopIdx_{0}, recordIdx_{0}, saveHwIdx_{0}
{

}

void SdbChartControlPanel::createControls()
{
    startButton_ = new SdbButton(QString("Start"), QColor(26,59,35), this->parentWidget());
    startButton_->setMinimumWidth(80);
    addWidget(startButton_, 0, Qt::Alignment());
    QObject::connect(startButton_, &SdbButton::released, this, &SdbChartControlPanel::startButtonHandler);

    stopButton_ = new SdbButton(QString("Stop"), QColor(110, 42, 36), this->parentWidget());
    stopButton_->setMinimumWidth(80);
    addWidget(stopButton_, 0, Qt::Alignment());
    QObject::connect(stopButton_, &SdbButton::released, this, &SdbChartControlPanel::stopButtonHandler);

    recordButton_ = new SdbButton(QString("Record"), QColor(64,64,64), this->parentWidget());
    recordButton_->setMinimumWidth(80);
    addWidget(recordButton_, 0, Qt::Alignment());
    QObject::connect(recordButton_, &SdbButton::released, this, &SdbChartControlPanel::recordButtonHandler);

    saveHwConfig_=  new SdbButton(QString("Save HW"), QColor(61,92,92), this->parentWidget());
    saveHwConfig_->setMinimumWidth(80);
    addWidget(saveHwConfig_, 0, Qt::Alignment());
    QObject::connect(saveHwConfig_, &SdbButton::released, this, &SdbChartControlPanel::saveButtonHandler);

    insertStretch(0);
}

