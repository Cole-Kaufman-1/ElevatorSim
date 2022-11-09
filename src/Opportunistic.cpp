#include "Opportunistic.h"
#include "ECS.h"

Opportunistic::Opportunistic(ECS* ecs): ecs(ecs) {}

void Opportunistic::makeDecision(int floorNum, int carNum, const QString& dir) {
    if (dir == "up" && ecs->getUpRequests()->contains(floorNum)) {
        ecs->getUpRequests()->remove(floorNum);
        ecs->getFloors()->at(floorNum - 1).serviced(dir);
        ecs->getElevators()->at(carNum - 1).stop();
    }
    else if (dir == "down" && ecs->getDownRequests()->contains(floorNum)) {
        ecs->getDownRequests()->remove(floorNum);
        ecs->getFloors()->at(floorNum - 1).serviced(dir);
        ecs->getElevators()->at(carNum - 1).stop();
    }
    else if (ecs->getCarRequests()->values(carNum).contains(floorNum)) {
        ecs->getCarRequests()->remove(carNum, floorNum);
        std::cout << "Destination button for floor " << floorNum << " turns off" << std::endl;
        ecs->updateFloorDisplay(floorNum);
        ecs->getElevators()->at(carNum - 1).setFloorNum(floorNum);
        ecs->getElevators()->at(carNum - 1).stop();
        ecs->getElevators()->at(carNum - 1).setIdle();
    }
    else if(floorNum == 1 || ecs->getElevators()->at(carNum - 1).isOperationHalted()) {
        ecs->getElevators()->at(carNum - 1).stop();
        ecs->getElevators()->at(carNum - 1).setIdle();
    }
    else {
        ecs->updateFloorDisplay(floorNum);
        ecs->getElevators()->at(carNum - 1).setFloorNum(floorNum);
        ecs->getElevators()->at(carNum - 1).start(dir);
    }
}



