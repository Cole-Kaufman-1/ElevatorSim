#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ECS.h"
#include "User.h"

class Elevator;
class Floor;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateFloorNumDisplay(int newFloor);
    void updateMsgDisplay(const QString& msg);
    User* getUser();

private:
    Ui::MainWindow *ui;
    void initConnections();
    void initSimulator(int numElevators,int numFloors);
    ECS* ecs;
    User* user;
    std::vector<Elevator> elevators;
    std::vector<Floor> floors;
    static const int DEFAULT_NUM_FLOORS;
    static const int DEFAUlT_NUM_ELEVATORS;

public slots:
    void pressDestinationButton();

private slots:
    void pressFloorUp();
    void pressFloorDown();
    void pressCloseDoorButton();
    void pressOpenDoorButton();
    void resetMsgDisplay();
    void pressHelpButton();
    void pressFireButton();
    void pressDoorObstrButton();
    void pressOverloadButton();
    void pressPowerOutageButton();
    void pressChangeStrategy();


};
#endif // MAINWINDOW_H
