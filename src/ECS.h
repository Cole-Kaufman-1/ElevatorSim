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

class ECS  {
    public:
        ECS(int numElevators, int numFloors, MainWindow* w, User* u);
        ~ECS();

        QSet<int>* getUpRequests();
        QSet<int>* getDownRequests();
        QMultiMap<int, int>* getCarRequests();
        std::vector<Elevator>* getElevators();
        std::vector<Floor>* getFloors();
        int getNumElevators();
        void setElevators(std::vector<Elevator>*);
        void setFloors(std::vector<Floor>*);
        User* getUser();
        MainWindow* getMainWindow();
        static const QStringList emergencyMsgList;


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
        bool isElevatorPassing(const QString& dir, int floorNum);
        bool isIdleAtLocation(int floorNum, const QString& dir);
        void delay(int ms);
        std::vector<Elevator>* elevators;
        std::vector<Floor>* floors;
        QSet<int> floorRequestsUp;
        QSet<int> floorRequestsDown;
        QMultiMap<int, int> carRequests;
        int numElevators;
        int numFloors;
        IStrategy* currentStrategy;
        bool swappedStrat;

};

#endif
