#include "Floor.h"

int Floor::nextFloorNum = 0;

Floor::Floor(ECS* ecs): theECS(ecs) {
    floorNum = ++nextFloorNum;
    floorButtons = new FloorButtons(this);
}
