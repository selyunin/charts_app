#ifndef QT_CMAKE_SDBMAINWINDOW_H
#define QT_CMAKE_SDBMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>

class SdbMainWindow : public QMainWindow {
public:
    SdbMainWindow(const std::string& title = "", const QApplication* app = nullptr);

    ~SdbMainWindow(){
        this->ptr_app = nullptr;
    }

    void keyPressEvent(QKeyEvent* event) override;

    const QApplication* ptr_app;
};


#endif //QT_CMAKE_SDBMAINWINDOW_H
