#ifndef FIRE_BUTTON_H
#define FIRE_BUTTON_H

#include "Elevator.h"

class FireButton : public Button {
    public:
        FireButton();
        void press();

    private:
        Elevator* Elevator;
};

#endif