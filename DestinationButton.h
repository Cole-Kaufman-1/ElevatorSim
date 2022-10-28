#ifndef DESTINATION_BUTTON_H
#define DESTIONATION_BUTTON_H

#include "Elevator.h"

class DestinationButton: public Button {
    public:
        DestinationButton();
        void press(int num);
        void turnOff();
        
    private:
    Elevator* elevator;
    int selectedFloor;
};

#endif