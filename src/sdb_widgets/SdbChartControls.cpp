#include "SdbChartControls.h"
#include "SdbButton.h"
#include <iostream>

void SdbChartControls::startButtonHandler()
{
    std::cout<<"Start button clicked: "<< startIdx_++<<std::endl;
}

void SdbChartControls::stopButtonHandler()
{
    std::cout<<"Stop button clicked: "<< stopIdx_++<<std::endl;
}

void SdbChartControls::recordButtonHandler()
{
    std::cout<<"Record button clicked: "<< recordIdx_++<<std::endl;
}

void SdbChartControls::saveButtonHandler()
{
    std::cout<<"Save button clicked: "<< saveHwIdx_++<<std::endl;
}

SdbChartControls::SdbChartControls(QWidget* parent):
        QHBoxLayout(parent), startIdx_{0}, stopIdx_{0}, recordIdx_{0}, saveHwIdx_{0}
{

}

void SdbChartControls::createControls()
{
    startButton_ = new SdbButton(QString("Start"), QColor(26,59,35), this->parentWidget());
    startButton_->setMinimumWidth(80);
    addWidget(startButton_, 0, Qt::Alignment());
    QObject::connect(startButton_, &SdbButton::released, this, &SdbChartControls::startButtonHandler);

    stopButton_ = new SdbButton(QString("Stop"), QColor(110, 42, 36), this->parentWidget());
    stopButton_->setMinimumWidth(80);
    addWidget(stopButton_, 0, Qt::Alignment());
    QObject::connect(stopButton_, &SdbButton::released, this, &SdbChartControls::stopButtonHandler);

    recordButton_ = new SdbButton(QString("Record"), QColor(64,64,64), this->parentWidget());
    recordButton_->setMinimumWidth(80);
    addWidget(recordButton_, 0, Qt::Alignment());
    QObject::connect(recordButton_, &SdbButton::released, this, &SdbChartControls::recordButtonHandler);

    saveHwConfig_=  new SdbButton(QString("Save HW"), QColor(61,92,92), this->parentWidget());
    saveHwConfig_->setMinimumWidth(80);
    addWidget(saveHwConfig_, 0, Qt::Alignment());
    QObject::connect(saveHwConfig_, &SdbButton::released, this, &SdbChartControls::saveButtonHandler);

    insertStretch(0);
}

