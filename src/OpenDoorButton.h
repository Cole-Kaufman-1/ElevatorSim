#ifndef OPEN_DOOR_BUTTON_H
#define OPEN_DOOR_BUTTON_H

#include "Elevator.h"

class OpenDoorButton {
    public:
        OpenDoorButton(Elevator* elevator);
        void press();
        void turnOff();

    private:
        Elevator* elevator;
        bool on;
};

#endif
