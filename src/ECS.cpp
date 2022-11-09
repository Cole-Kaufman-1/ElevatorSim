#include "ECS.h"
#include "IStrategy.h"
#include "Opportunistic.h"
#include "AI.h"
#include <QTimer>
#include <QEventLoop>

const QStringList ECS::emergencyMsgList = {
    "Fire button pressed, please disembark once the next floor is reached",
    "Door blocked repeatedly, please unobstruct door to proceed",
    "Elevator is overloaded, please reduce load to proceed",
    "A power outage has occured, please disembark once the next floor is reached"
};

ECS::ECS(int numElevators, int numFloors, MainWindow* w, User* u): w(w), u(u), numElevators(numElevators), numFloors(numFloors) {
    //set initial strategy to opportunistic
    currentStrategy = new Opportunistic(this);
    swappedStrat = false;
}

ECS::~ECS(){

}

QSet<int>* ECS::getUpRequests() {
    return &floorRequestsUp;
}

QSet<int>* ECS::getDownRequests() {
    return &floorRequestsDown;
}


void ECS::floorRequest(const QString& dir, int floorNum) {
    if (dir == "up") {
        floorRequestsUp.insert(floorNum);
    }
    else {
        floorRequestsDown.insert(floorNum);
    }
    if (moveIdle(dir, floorNum)) {
        for(int i = 0;i < numElevators;++i) {
            if(elevators->at(i).isIdle()) {
                elevators->at(i).start(dir);
                return;
            }
        }
    }
}

bool ECS::moveIdle(const QString& dir, int floorNum) {
    if(isElevatorPassing(dir, floorNum) || isIdleAtLocation(floorNum, dir)){
        return false;
    }
    else{
        return true;
    }
}

bool ECS::isElevatorPassing(const QString& dir, int floorNum) {
    if (dir == "up") {
        for (int i = 0; i < numElevators; ++i){
            Elevator e = elevators->at(i);
            if (e.getDirection() == dir && e.getFloorNum() < floorNum) {
                return true;
            }
        }
    }
    else{
        for (int i = 0; i < numElevators; ++i){
            Elevator* e = &elevators->at(i);
            if (e->getDirection() == dir && e->getFloorNum()> floorNum) {
                return true;
            }
        }
    }
    return false;
}

bool ECS::isIdleAtLocation(int floorNum, const QString& dir) {
    for(int i = 0;i < numElevators;++i) {
        if(elevators->at(i).isIdle() && floorNum == elevators->at(i).getFloorNum()){
            currentStrategy->makeDecision(floorNum, elevators->at(i).getCarNum(), dir);
            return true;
        }
    }
    return false;
}

void ECS::newFloor(int newfloorNum, int carNum) {
    delay(1000);
    currentStrategy->makeDecision(newfloorNum, carNum, elevators->at(carNum - 1).getDirection());
}

void ECS::carRequest(int carNum, int floorNum) {
    if (!carRequests.values(carNum).contains(floorNum)) {
        carRequests.insert(carNum, floorNum);
        std::cout << "Destination button for floor " << floorNum << " illuminates" << std::endl;
    }

    //if the elevator door isn't closed at the time of the request send another in 10 seconds
    if (elevators->at(carNum - 1).isDoorOpen()) {
        QTimer::singleShot(10000, w, &MainWindow::pressDestinationButton);
    }
    else {
        readyToMove(carNum);
    }
}

void ECS::readyToMove(int carNum) {
    if (carRequests.values().at(0) > elevators->at(carNum - 1).getFloorNum()){
        elevators->at(carNum - 1).start("up");
    }
    else {
        elevators->at(carNum - 1).start("down");
    }
}

void ECS::changeStrategy() {
    currentStrategy = new AI();
}

void ECS::handleCloseDoorButton(int carNum) {
    if(w->getUser()->inElevator()) {
        std::cout << "Close door button pressed" << std::endl;
        elevators->at(carNum - 1).closeDoor();
    }
}

void ECS::handleFire() {
    w->updateMsgDisplay(emergencyMsgList.at(0));
    for (int i = 0;i<numElevators;++i) {
        elevators->at(i).stop();
    }
    carRequests.clear();
    std::cout << "All elevators stoped due to fire" << std::endl;
}

void ECS::handleOverload(int carNum) {
    w->updateMsgDisplay(emergencyMsgList.at(2));
    QString dir = elevators->at(carNum - 1).getDirection();
    elevators->at(carNum - 1).stop();
    std::cout << "Elevator stoped due to overloading, will continue once weight is reduced" << std::endl;
    elevators->at(carNum - 1).start(dir);
}

void ECS::handlePowerOutage() {
    w->updateMsgDisplay(emergencyMsgList.at(3));
    for (int i = 0;i<numElevators;++i) {
        elevators->at(i).stop();
    }
    carRequests.clear();
    std::cout << "All elevators stoped due to power outage" << std::endl;
}

void ECS::handleObstDoor() {
    w->updateMsgDisplay(emergencyMsgList.at(1));
}

void ECS::updateFloorDisplay(int num) {
    w->updateFloorNumDisplay(num);
}

void ECS::setElevators(std::vector<Elevator>* e) {
    elevators = e;
}

void ECS::setFloors(std::vector<Floor>* f) {
    floors = f;
}

void ECS::delay(int ms) {
    QTimer timer;
    QEventLoop loop;
    timer.connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(ms);
    loop.exec();
}

User* ECS::getUser() {
    return u;
}

QMultiMap<int, int>* ECS::getCarRequests() {
    return &carRequests;
}

std::vector<Elevator>* ECS::getElevators() {
    return elevators;
}

std::vector<Floor>* ECS::getFloors() {
    return floors;
}

