#include "Floor.h"

int Floor::nextFloorID = 0;

Floor::Floor(ECS* ecs, int maxFloor): ecs(ecs), floorNum(++nextFloorID), upWaiting(false), downWaiting(false), maxFloor(maxFloor) {
}

int Floor::getFloorNum() {
    return floorNum;
}

void Floor::pressUp() {
    if (!upWaiting && floorNum < maxFloor) {
        upWaiting = true;
        std::cout << "Up button for floor " << floorNum <<" illuminates" << std::endl;
        ecs->floorRequest("up", floorNum);
    }
}

void Floor::pressDown() {
    if (!downWaiting && floorNum > 1) {
        downWaiting = true;
        std::cout << "Down button for floor " << floorNum <<" illuminates" << std::endl;
        ecs->floorRequest("down", floorNum);
    }
}

void Floor::turnOffUp() {
    upWaiting = false;
    std::cout << "Up button for floor " << floorNum <<" turns off" << std::endl;

}

void Floor::turnOffDown() {
    upWaiting = false;
    std::cout << "Down button for floor " << floorNum <<" turns off" << std::endl;
}

void Floor::serviced(const QString& dir) {
    if(dir == "up"){
        turnOffUp();
    }
    else if(dir == "down") {
        turnOffDown();
    }
}
