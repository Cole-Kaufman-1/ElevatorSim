#ifndef OPEN_DOOR_BUTTON_H
#define OPEN_DOOR_BUTTON_H

#include "Elevator.h"

class OpenDoorButton : public Button {
    public:
        OpenDoorButton();
        void press();

    private:
        Elevator* Elevator;
};

#endif