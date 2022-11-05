#ifndef CLOSE_DOOR_BUTTON_H
#define CLOSE_DOOR_BUTTON_H

#include "Elevator.h"

class CloseDoorButton : public Button {
    public:
        CloseDoorButton();
        void press();

    private:
        Elevator* Elevator;
};

#endif