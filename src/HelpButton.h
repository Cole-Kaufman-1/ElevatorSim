#ifndef HELP_BUTTON_H
#define HELP_BUTTON_H

#include "Elevator.h"

class HelpButton : public Button {
    public:
        HelpButton();
        void press();

    private:
        Elevator* Elevator;
};

#endif