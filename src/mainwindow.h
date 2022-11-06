#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ECS.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initConnections();
    ECS* ecs;

private slots:
    void pressFloorUp();
    void pressFloorDown();
    /*
    void pressCloseDoor();
    void pressOpenDoor();
    void pressHelp();
    void pressFire();
    void pressOverload();
    void pressPowerout();
    void pressDoorObst();
    void pressSwapStrategy();
    void pressDestGo()
    */

};
#endif // MAINWINDOW_H
