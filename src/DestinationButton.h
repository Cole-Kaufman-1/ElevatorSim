#ifndef DESTINATION_BUTTON_H
#define DESTINATION_BUTTON_H

#include "Elevator.h"

class DestinationButton {
    public:
        DestinationButton(Elevator* elevator);
        void press(int num);
        void turnOff();

    private:
    Elevator* elevator;
    int selectedFloor;
    bool on;
};

#endif
