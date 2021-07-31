#ifndef QT_CMAKE_SDBMAINWINDOW_H
#define QT_CMAKE_SDBMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>
#include <QString>

class SdbMainWindow : public QMainWindow {
    QRect windowPosition;
    bool everUpdated;
public:
    SdbMainWindow(const QString& title = "");

    ~SdbMainWindow(){    }

    void keyPressEvent(QKeyEvent* event) override;

    void setDarkTheme();

public slots:
    void handleShow(int showValue);
};


#endif //QT_CMAKE_SDBMAINWINDOW_H
