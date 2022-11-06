#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include "FloorButtons.h"
#include "ECS.h"

class ECS;
class FloorButtons;

class Floor {
    public:
        Floor(ECS* ecs);
        void serviced(const std::string& direction);

        FloorButtons* getFloorButton();
        void setFloorButton();

        ECS* getECS();
        void setECS();

    protected:
        static int nextFloorNum;

    private:
        int floorNum;
        ECS* theECS;
        FloorButtons* floorButtons;
};

#endif
