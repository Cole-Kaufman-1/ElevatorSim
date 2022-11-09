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

/* Class Purpose: Transports passengers from floor to floor, relaying and receiving information from the ECS
 *
 * Data Members:
 * -int carNum: number of the current car (carNum - 1) = index in vector
 * -int floorNum: current floor the elevator is on or passing
 * -int doorObstCount: how many times the door obstacle button has been pressed on a floor
 * -bool idle: indicates if current performing a job
 * -bool doorOpen: indicates if door is open
 * -bool fireButtonOn: indicates if the fire button is on
 * -bool helpButtonOn: indicates if the help button is on
 * -bool overloadButtonOn: indicates if the help button is on
 * -bool powerOutageButtonOn: indicates if the help button is on
 * -bool openDoorButtonOn: indicates if the help button is being held
 * -bool cameFromFloorReq: indicates if the elevator just came from a floor request
 * -QString direction: indicates the current direction of the elevator
 * -ECS* ecs: a pointer to the ECS, used for passing info
 * -std::vector<int> floorsToVisit: a list of floors to visit, used by the AI strategy
 * -static int nextElevatorNum: used in creation of the elevator to number them 1..n
 * -static const QStringList emergencySpeakerList: a list of messages the speaker(console) will output in safety situations
 *
 * Class Functions:
 * Getters for direction, floorNum, carNum, floorsToVisit
 * Setters for floorNum, idle, cameFromFloorReq
 *
 * void stop(): stops the elevator and opens it's doors
 * void start(const QString& dir): starts the elevator moving in a specified direction
 * void newFloor(int floorNum): informs the ECS that a new floor is about to be reached, acts as a sensor
 * void carRequest(int floorNum): informs the ECS of a destination button being pushed
 * bool isIdle() const: returns idle status
 * void openDoor(): opens the elvator door and outputs text depending on state of the user, elevator and previous request
 * void closeDoor(): closes the door and ouputs info
 * void helpButtonPressed(): outputs speaker text out the help button being pressed
 * void fireButtonPressed(): outputs speaker text out the fire button being pressed, then tells the ECS to handle the fire
 * void doorObstButtonPressed(): outputs speaker text out the door obstacle button being pressed, if pressed 3 times on a floor outputs to the speaker and display
 * void overloadButtonPressed(): outputs speaker text out the overload button being pressed, tells the ECS to handle it
 * void powerOutageButtonPressed(): outputs speaker text out the power outage button being pressed, tells the ECS to handle it
 * void closeDoorButtonPressed(): lets the ECS handle the door button being pressed, only works if the user is in the elevator
 * void openDoorButtonPressed(): handles press and release of open door button, does not open the door if already closed, only keeps it open while pressed
 * bool isDoorOpen() const: returns state of the door
 * bool isOperationHalted() const: returns state of elevator if it's fire or power outage button has been pressed
 *
 * -void delay(int ms): a delay function to delay the door closing by 10 seconds, doesnt block UI
 */

class ECS;

class Elevator{
    public:
        Elevator(ECS* ecs);
        ~Elevator();

        const QString& getDirection() const;
        int getFloorNum() const;
        int getCarNum() const;
        std::vector<int>* getFloorsToVisit();

        void setFloorNum(int newFloorNum);
        void setIdle();
        void setCameFromFloorReq(bool);

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
