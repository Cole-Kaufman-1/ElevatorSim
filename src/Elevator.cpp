#include "Elevator.h"

int Elevator::nextElevatorNum = 0;

Elevator::Elevator(QObject *parent): QObject(parent){}

Elevator::Elevator(ECS* ecs): theECS(ecs) {
    carNum = ++nextElevatorNum;
    floorNum = 1;
    direction = "";
    bool idle = true;
    display = new Display(this);
    door = new Door(this);

    destButton = new DestinationButton(this);
    closeDoorButton = new CloseDoorButton(this);
    openDoorButton = new OpenDoorButton(this);
    helpButton = new HelpButton(this);
    fireButton = new FireButton(this);

}

Elevator::~Elevator() {

}


void Elevator::stop() {

}

void Elevator::start(QString direction) {

}

void newFloor(int floorNum) {

}

void carRequest(int floorNum){

}

void Elevator::openRequest() {

}

void Elevator::closeRequest() {

}

void Elevator::outputFireEvent() {

}

void Elevator::outputDoorObstructed() {

}

void Elevator::outputOverload() {

}

void Elevator::outputPowerOutage() {

}
