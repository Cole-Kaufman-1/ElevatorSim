#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "ui_mainwindow.h"
#include "ECS.h"
#include <QTimer>
#include <QEventLoop>
#include <vector>

class ECS;

class Elevator{
    public:
        Elevator(ECS* ecs);
        ~Elevator();

        const QString& getDirection() const;
        int getFloorNum() const;
        int getCarNum() const;
        void setFloorNum(int newFloorNum);
        void setIdle();
        void setCameFromFloorReq(bool);
        std::vector<int>* getFloorsToVisit();

        void stop();
        void start(const QString& dir);
        void newFloor(int floorNum);
        void carRequest(int floorNum);
        bool isIdle() const;
        void openDoor();
        void closeDoor();
        void helpButtonPressed();
        void fireButtonPressed();
        void doorObstButtonPressed();
        void overloadButtonPressed();
        void powerOutageButtonPressed();
        void closeDoorButtonPressed();
        void openDoorButtonPressed();
        bool isDoorOpen() const;
        bool isOperationHalted() const;


    private:
        int carNum;
        int floorNum;
        int doorObstCount;
        bool idle;
        bool doorOpen;
        bool fireButtonOn;
        bool helpButtonOn;
        bool overloadButtonOn;
        bool powerOutageButtonOn;
        bool openDoorButtonOn;
        bool cameFromFloorReq;
        QString direction;
        ECS* ecs;
        std::vector<int> floorsToVisit;
        static int nextElevatorNum;
        static const QStringList emergencySpeakerList;
        void delay(int ms);


};

#endif
