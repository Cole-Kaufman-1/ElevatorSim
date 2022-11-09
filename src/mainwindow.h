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

/* Class Purpose: Main window of the application, receiving button presses and sometimes changes based on the button pressed
 *
 * Data Members:
 * -Ui::MainWindow *ui: the application's GUI
 * -ECS* ecs: the main control unit of the elevator
 * -User* user: holds user state information
 * -std::vector<Elevator> elevators: a vector containing all elevators
 * -std::vector<Floor> floors: a vector containing all floors
 * -const int DEFAULT_NUM_FLOORS: number of floors
 * -const int DEFAUlT_NUM_ELEVATORS: number of elevators
 *
 * Class Functions:
 * Getters for user
 *
 * +void updateFloorNumDisplay(int newFloor): updates floor number in elevator
 * +void updateMsgDisplay(const QString& msg): updates message display in elevator
 * -void initConnections(): initializes slot connections for UI interaction
 * -void initSimulator(int numElevators,int numFloors): initializes simulator objects
 *
SLOTS: (self-explanatory)
    void pressDestinationButton();
    void pressFloorUp()
    void pressFloorDown()
    void pressCloseDoorButton()
    void pressOpenDoorButton()
    void resetMsgDisplay()
    void pressHelpButton()
    void pressFireButton()
    void pressDoorObstrButton()
    void pressOverloadButton()
    void pressPowerOutageButton()
    void pressChangeStrategy()
 *
 */

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
    ECS* ecs;
    User* user;
    std::vector<Elevator> elevators;
    std::vector<Floor> floors;
    const int DEFAULT_NUM_FLOORS;
    const int DEFAUlT_NUM_ELEVATORS;

    void initConnections();
    void initSimulator(int numElevators,int numFloors);

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
