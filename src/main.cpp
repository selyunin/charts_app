/**
 * author: selyunin
 */
#include "SdbAppControlWidget.h"
#include "SdbMainWindow.h"
#include <QDesktopWidget>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>
#include <QStyleFactory>
#include <QtWidgets/QApplication>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QApplication::setStyle(QStyleFactory::create("fusion"));
    QPalette palette;

    palette.setColor(QPalette::WindowText, QColor(0xd6, 0xd6, 0xd6));
    palette.setColor(QPalette::Button, QColor(10, 10, 10));
    palette.setColor(QPalette::Light, QColor(10, 10, 10));
    palette.setColor(QPalette::Midlight, QColor(10, 10, 10));
    palette.setColor(QPalette::Dark, QColor(10, 10, 10));
    palette.setColor(QPalette::Mid, QColor(10, 10, 10));

    palette.setColor(QPalette::Text, Qt::blue);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::Base, QColor(230,240,230));
    palette.setColor(QPalette::Window, QColor(0x12, 0x12, 0x12));
    palette.setColor(QPalette::Shadow, Qt::cyan);

    palette.setColor(QPalette::Highlight, Qt::green);
    palette.setColor(QPalette::HighlightedText, Qt::red);

    palette.setColor(QPalette::Link, Qt::green);
    palette.setColor(QPalette::LinkVisited, Qt::red);

    palette.setColor(QPalette::AlternateBase, Qt::green);

    palette.setColor(QPalette::NoRole, Qt::green);

    palette.setColor(QPalette::ToolTipBase, Qt::cyan);
    palette.setColor(QPalette::ToolTipText, Qt::blue);

    palette.setColor(QPalette::Active, QPalette::Button, QColor(10, 10, 10));
    palette.setColor(QPalette::Active, QPalette::Window, QColor(10, 10, 10));
    palette.setColor(QPalette::Disabled, QPalette::Window, Qt::yellow);
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::yellow);
    palette.setColor(QPalette::Disabled, QPalette::WindowText, Qt::cyan);
    palette.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
    palette.setColor(QPalette::Disabled, QPalette::Button, Qt::yellow);
    palette.setColor(QPalette::Disabled, QPalette::Base, Qt::darkGray);
    palette.setColor(QPalette::Disabled, QPalette::Light, Qt::yellow);

    QApplication::setPalette(palette);

    SdbMainWindow app_control("IMU Charts");
    SdbAppControlWidget app_control_widget;
    app_control.setCentralWidget(&app_control_widget);
    app_control.resize(250, 400);
    app_control.move(200, 200);

    app_control.show();
    app_control.activateWindow();

    return app.exec();
}