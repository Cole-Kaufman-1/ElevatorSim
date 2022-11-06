#ifndef DOOR_H
#define DOOR_H

#include "Elevator.h"

class Elevator;

class Door {
    public:
        Door(Elevator* elevator);
        bool openDoor();
        bool closeDoor();
    private:
        bool isOpen;
        bool isBlocked;
        Elevator* elevator;
};

#endif
