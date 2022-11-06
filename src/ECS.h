#ifndef ECS_H
#define ECS_H

#include <iostream>
#include <vector>
#include <QObject>
#include <map>
#include "Elevator.h"
#include "IStrategy.h"
#include "Floor.h"

class Floor;

class ECS : public QObject  {
    public:
        explicit ECS(QObject *parent = nullptr);
        ECS(int numElevators, int numFloors);
        ~ECS();


        std::map<int, QString> getRequests();
        std::vector<Elevator*> getElevators();

        void floorRequest(QString, int floorNum);
        void newFloor(int floorNum, int carNum);
        void carRequest(int carNum, int floorNum);
        void readyToMove(int carNum);
        void changeStrategy();
        void handleHelp(int floorNum, int carNum);
        void handleFire(int floorNum, int carNum);
        void handleOverload(int floorNum, int carNum);
        void handlePowerOutage(int floorNum, int carNum);

    private:
        std::vector<Elevator*> elevators;
        std::vector<Floor*> floors;
        std::map<int, QString> floorRequests;
        std::map<int, int> carRequests;
        int numElevators;
        int numFloors;
        IStrategy* currentStrategy;
        std::vector<IStrategy> strategies;
        Q_OBJECT

};

#endif
