#ifndef FLOOR_BUTTON_H
#define FLOOR_BUTTON_H

#include <string>;
#include "Button.h";
#include "Floor.h";

class FloorButton: public Button {
    public:
        FloorButton();
        void press();
        void turnOff();

    private:
        bool waitingUp;
        bool waitingDown;
        Floor* floor;
};
#endif