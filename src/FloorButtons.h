#ifndef FLOOR_BUTTONS_H
#define FLOOR_BUTTONS_H

#include <string>
#include "Floor.h"

class Floor;

class FloorButtons {
    public:
        FloorButtons(Floor* floor);
        void pressUp();
        void pressDown();
        void turnOffUp();
        void turnOffDown();

    private:
        bool upOn;
        bool downon;
        Floor* floor;
};
#endif
