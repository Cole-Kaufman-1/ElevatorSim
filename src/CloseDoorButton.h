#ifndef CLOSE_DOOR_BUTTON_H
#define CLOSE_DOOR_BUTTON_H

#include "Elevator.h"

class CloseDoorButton {
    public:
        CloseDoorButton(Elevator* elevator);
        void press();
        void turnOff();

    private:
        Elevator* elevator;
        bool on;
};

#endif
