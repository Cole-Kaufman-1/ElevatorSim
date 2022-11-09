#include "Elevator.h"
#include "mainwindow.h"
#include <QString>
#include <QTimer>
#include <QEventLoop>
#include <QThread>


int Elevator::nextElevatorNum = 0;
const QStringList Elevator::emergencyMsgList = {
    "Fire button pressed, please disembark once the next floor is reached",
    "Door blocked repeatedly, please unobstruct door to proceed",
    "Elevator is overloaded, please reduce load to proceed",
    "A power outage has occured, please disembark once the next floor is reached"
};

Elevator::Elevator(ECS* e): ecs(e), carNum(++nextElevatorNum), floorNum(1), direction(""), doorObstCount(0) {
    //elevator starts idle
    idle = true;
    //set initial button on values to false
    doorOpen = helpButtonOn = overloadButtonOn = fireButtonOn = powerOutageButtonOn = openDoorButtonOn = false;
}

Elevator::~Elevator() {
}

const QString& Elevator::getDirection() const {
    return direction;
}

void Elevator::stop() {
    direction = "";
    openDoor();
}

void Elevator::openDoor() {
    //only open the door if it's currently closed and either the user is in the elevator or the operation isn't haulted (fire or power outage)
    if (!doorOpen && (ecs->getUser()->inElevator() || !isOperationHalted())) {
        std::cout << "Elevator " << carNum << " rings its bell" << std::endl;
        doorOpen = true;
        std::cout << "Elevator " << carNum << " opens its doors" << std::endl;
        if (ecs->getUser()->getCarNum() > 0) {
            std::cout << "User exits elevator "  << carNum << " on floor " << floorNum << std::endl;
            ecs->getUser()->setCarNum(0);
            ecs->getUser()->setFloor(floorNum);
        }
        else {
            if (!powerOutageButtonOn && !fireButtonOn){
                std::cout << "User enters elevator "  << carNum << std::endl;
                ecs->getUser()->setCarNum(1);
            }
        }
        delay(10000);
        if (!openDoorButtonOn) {
            closeDoor();
        }
    }
}

void Elevator::closeDoor() {
    if (doorOpen) {
        std::cout << "Elevator " << carNum << " rings its bell" << std::endl;
        doorOpen = false;
        std::cout << "Elevator " << carNum << " closes its doors" << std::endl;
    }
}

int Elevator::getFloorNum() const {
    return floorNum;
}

void Elevator::setFloorNum(int newFloorNum) {
    floorNum = newFloorNum;
}

void Elevator::setIdle() {
    idle = true;
}

void Elevator::start(const QString& dir) {
    direction = dir;
    if (dir == "up"){
        newFloor(floorNum+1);
    }
    else if (dir == "down"){
        newFloor(floorNum-1);
    }
}

void Elevator::newFloor(int newFloorNum) {
    doorObstCount = 0;
    helpButtonOn = overloadButtonOn = fireButtonOn = powerOutageButtonOn = false;
    ecs->newFloor(newFloorNum, carNum);
}

void Elevator::carRequest(int floorNum){
    ecs->carRequest(carNum, floorNum);
}

bool Elevator::isIdle() const {
    return idle;
}

bool Elevator::isDoorOpen() const {
    return doorOpen;
}

bool Elevator::isOperationHalted() const {
    return fireButtonOn || powerOutageButtonOn;
}

void Elevator::helpButtonPressed() {
    // can only be pressed once per floor
    if (!helpButtonOn) {
        helpButtonOn = true;
        std::cout << "Help button pressed" << std::endl;
        std::cout << "(speaker system)Connecting to building safety, if no response a 911 call will be placed" << std::endl;
    }
}

void Elevator::fireButtonPressed() {
    // can only be pressed once per floor as the elevator moves in response to this button press
    if (!fireButtonOn) {
        fireButtonOn = true;
        std::cout << "Fire button pressed" << std::endl;
        std::cout << "(speaker system) " << emergencyMsgList.at(0).toStdString() << std::endl;
        ecs->handleFire();
    }
}

void Elevator::doorObstButtonPressed() {
    //door button can be pressed twice per floor stop before warning is displayed, subsequent pressed do nothing
    if (doorObstCount <= 1) {
        ++doorObstCount;
        std::cout << "Door Obstacle button pressed" << std::endl;
    }
    else if(doorObstCount == 2) {
        std::cout << "(speaker system) " << emergencyMsgList.at(1).toStdString() << std::endl;
        ecs->handleObstDoor();
        ++doorObstCount;
    }
}

void Elevator::overloadButtonPressed() {
    //can only be pressed once per floor, message disapears after 5 seconds implying the door is not longer obstructed.
    if(!overloadButtonOn) {
        overloadButtonOn = true;
        std::cout << "Overload button pressed" << std::endl;
        std::cout << "(speaker system) " << emergencyMsgList.at(2).toStdString() << std::endl;
        ecs->handleOverload(carNum);
    }
}


void Elevator::powerOutageButtonPressed() {
    // can only be pressed once per floor as the elevator moves in response to this button press
    if (!powerOutageButtonOn) {
        powerOutageButtonOn = true;
        std::cout << "Power outage button pressed" << std::endl;
        std::cout << "(speaker system) " << emergencyMsgList.at(3).toStdString() << std::endl;
        ecs->handlePowerOutage();
    }
}

void Elevator::openDoorButtonPressed() {
    /*
    on initial press false turns to true keeping the door open
    on release function is called again, value will be true swapped to false, thus close door on release
    assignment did no specify if subsequent presses should open the door so although logically this makes sense I ommited this functionality
    */
    if(openDoorButtonOn) {
        closeDoor();
    }
    openDoorButtonOn = !openDoorButtonOn;


}

void Elevator::closeDoorButtonPressed() {
    ecs->handleCloseDoorButton(carNum);
}

int Elevator::getCarNum() const {
    return carNum;
}

void Elevator::delay(int ms) {
    QTimer timer;
    QEventLoop loop;
    timer.connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(ms);
    loop.exec();
}




