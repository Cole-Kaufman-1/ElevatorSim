#ifndef HELP_BUTTON_H
#define HELP_BUTTON_H

#include "Elevator.h"

class HelpButton {
    public:
        HelpButton(Elevator* elevator);
        void press();
        void turnOff();

    private:
        Elevator* elevator;
        bool on;
};

#endif
