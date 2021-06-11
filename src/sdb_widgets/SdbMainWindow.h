#ifndef QT_CMAKE_SDBMAINWINDOW_H
#define QT_CMAKE_SDBMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>

class SdbMainWindow : public QMainWindow {
public:
    SdbMainWindow(const std::string& title = "");

    ~SdbMainWindow(){    }

    void keyPressEvent(QKeyEvent* event) override;

    void setDarkTheme();
};


#endif //QT_CMAKE_SDBMAINWINDOW_H
