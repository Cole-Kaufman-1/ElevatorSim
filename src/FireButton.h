#ifndef FIRE_BUTTON_H
#define FIRE_BUTTON_H

#include "Elevator.h"

class FireButton {
    public:
        FireButton(Elevator* elevator);
        void press();
        void turnOff();

    private:
        Elevator* elevator;
        bool on;
};

#endif
