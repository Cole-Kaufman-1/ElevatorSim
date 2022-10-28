#ifndef DOOR_H
#define DOOR_H

#include "Elevator.h"

class Door {
    public:
        Door();
        bool openDoor();
        bool closeDoor();
    private:
        bool isOpen;
        bool isBlocked;
        Elevator* elevator;
};

#endif