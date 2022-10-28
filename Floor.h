#ifndef FLOOR_H
#define FLOOR_H

#include <string>;
#include "FloorButton.h";
#include "ECS.h";

class Floor {
    public:
        Floor(int floorNum, ECS* ecs, FloorButton* floorButton);
        void serviced(const std::string& direction);

        FloorButton getFloorButton();
        FloorButton setFloorButton();
        ECS getECS();
        ECS setECS();
    private:
        int floorNum;
        ECS* theECS;
        FloorButton* floorButton;
};

#endif