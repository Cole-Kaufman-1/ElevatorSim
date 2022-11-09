#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <QSet>
#include <QObject>
#include <QMultiMap>
#include "User.h"
#include "Elevator.h"
#include "IStrategy.h"
#include "Floor.h"
#include "mainwindow.h"

class Floor;
class Elevator;
class MainWindow;

/* Class Purpose: Manages interactions between floors, elevators and the main window
 *
 * Data Members:
 * -MainWindow* w: a pointer to the mainwindow
 * -User* u: a pointer to the user object
 * -std::vector<Elevator>* elevators: a pointer to the elevators vector
 * -std::vector<Floor>* floors: a pointer to the floors vector
 * -QSet<int> floorRequestsUp: set of floor request to go up
 * -QSet<int> floorRequestsDown: set of floor request to go down
 * -QMultiMap<int, int> carRequests: multimap of car requests
 * -int numElevators: the number of elevators in the simulation
 * -int numFloors: the number of floors in the simulation
 * -IStrategy* currentStrategy: a pointer to the current allocation strategy
 * -bool swappedStrat: a bool to flag if the strategy has changed
 * -static const QStringList emergencyMsgList: a list of emergency messages for the UI to display
 *
 * Class Functions:
 * Getters for upRequests, downRequests, carRequests, elavators, floors, numElevators, user, mainWindow,
 * Setters for elevators, floors
 *
 * void floorRequest(void floorRequest(const QString& dir, int floorNum): delegates floorRequest actions to the current strategy's implementation
 * void newFloor(int floorNum, int carNum): called before arriving at a new floo, delays 1.5 seconds before asking the current stratgy to decide on an action
 * void carRequest(int carNum, int floorNum): delegates carRequets actions to the current strategy's implementation
 * void readyToMove(int carNum): decides which direction an elevator should move based on state of requests and strategy
 * bool moveIdle(const QString& dir, int floorNum): moves an idle elevator if no active elevators will pass a floor request
 * void changeStrategy(): swaps strategy from Opportunistic to AI
 * void handleCloseDoorButton(int carNum): updates user state and elevator state
 * void handleFire(): handles the user pressing the fire button by stopping all elevators and updating UI
 * void handleOverload(int carNum): handles the user pressing the overload button by stopping the elevators and updating UI
 * void handleObstDoor(): handles the user pressing the door obstacle button updating UI, 3 presses on a single flooor trigger the UI update
 * void handlePowerOutage(): handles the user pressing the power outage button by stopping all elevators and updating UI
 * void updateFloorDisplay(int floorNum): updates the floor display in the elevator upon reaching a new floor
 *
 * -bool isElevatorPassing(const QString& dir, int floorNum): helper function for moveIdle, checks if an active elevator is passing
 * -bool isIdleAtLocation(int floorNum, const QString& dir): helper fucntion for moveIdle, check if the elevator is idle at request location
 * -void delay(int ms): creates a delay that doesnt block UI
 */

class ECS  {
    public:
        ECS(int numElevators, int numFloors, MainWindow* w, User* u);
        ~ECS();

        QSet<int>* getUpRequests();
        QSet<int>* getDownRequests();
        QMultiMap<int, int>* getCarRequests();
        std::vector<Elevator>* getElevators();
        std::vector<Floor>* getFloors();
        User* getUser();
        MainWindow* getMainWindow();
        int getNumElevators();

        void setElevators(std::vector<Elevator>*);
        void setFloors(std::vector<Floor>*);

        void floorRequest(const QString& dir, int floorNum);
        void newFloor(int floorNum, int carNum);
        void carRequest(int carNum, int floorNum);
        void readyToMove(int carNum);
        bool moveIdle(const QString& dir, int floorNum);
        void changeStrategy();
        void handleCloseDoorButton(int carNum);
        void handleFire();
        void handleOverload(int carNum);
        void handleObstDoor();
        void handlePowerOutage();
        void updateFloorDisplay(int floorNum);

    private:
        MainWindow* w;
        User* u;
        std::vector<Elevator>* elevators;
        std::vector<Floor>* floors;
        QSet<int> floorRequestsUp;
        QSet<int> floorRequestsDown;
        QMultiMap<int, int> carRequests;
        int numElevators;
        int numFloors;
        IStrategy* currentStrategy;
        bool swappedStrat;
        static const QStringList emergencyMsgList;

        bool isElevatorPassing(const QString& dir, int floorNum);
        bool isIdleAtLocation(int floorNum, const QString& dir);
        void delay(int ms);

};

#endif
