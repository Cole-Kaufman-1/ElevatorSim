#include "ECS.h"

ECS::ECS(QObject *parent): QObject(parent){}

ECS::ECS(int numElevators, int numFloors): numElevators(numElevators), numFloors(numFloors) {
    //create floor and elevator objects
    for (int i = 0; i < numElevators; ++i) {
        elevators.push_back(new Elevator(this));
    }
    for (int i = 0; i < numFloors; ++i) {
        floors.push_back(new Floor(this));
    }
    std::cout << "\nCreated floors and elevators!" << std::endl;
}

ECS::~ECS(){

}

std::map<int, QString> ECS::getRequests() {
    return floorRequests;
}

std::vector<Elevator*> ECS::getElevators() {
    return elevators;
}

void ECS::floorRequest(QString dir, int floorNum) {

}

void ECS::newFloor(int floorNum, int carNum) {

}

void ECS::carRequest(int carNum, int floorNum) {

}

void ECS::readyToMove(int carNum) {

}

void ECS::changeStrategy() {

}

void ECS::handleHelp(int floorNum, int carNum) {

}

void ECS::handleFire(int floorNum, int carNum) {

}

void ECS::handleOverload(int floorNum, int carNum) {

}

void ECS::handlePowerOutage(int floorNum, int carNum) {

}



