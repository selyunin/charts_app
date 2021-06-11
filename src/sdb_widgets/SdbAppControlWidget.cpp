#include "SdbAppControlWidget.h"
#include "SdbRadioButton.h"

SdbAppControlWidget::SdbAppControlWidget()
    : QWidget(), rawChartController_(this)
{
    createWidget();
}

void SdbAppControlWidget::createWidget()
{
    rawChartRBtn_ = new QCheckBox("Raw Chart", this);
//    rawChartRBtn_->setChecked(true);
    QObject::connect(rawChartRBtn_, &QCheckBox::stateChanged, &rawChartController_, &SdbRawChartController::handleRawChartWindow);
//    rawChartRBtn_->setStyleSheet("QCheckBox { padding: 20; color: white };\n QCheckBox::indicator {\n"
//                  "    color: black;\n"
//                  "}");
    rawChartRBtn_->update();
    jsonConfig_.parseSettings();

}
