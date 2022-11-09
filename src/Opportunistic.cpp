#include "Opportunistic.h"
#include "ECS.h"

Opportunistic::Opportunistic(ECS* ecs): ecs(ecs) {}

void Opportunistic::makeDecision(int floorNum, int carNum, const QString& dir) {
    //handle up floor request
    if (dir == "up" && ecs->getUpRequests()->contains(floorNum)) {
        ecs->getUpRequests()->remove(floorNum);
        ecs->getFloors()->at(floorNum - 1).serviced(dir);
        ecs->getElevators()->at(carNum - 1).setCameFromFloorReq(true);
        ecs->getElevators()->at(carNum - 1).stop();
    }
    //handle down floor request
    else if (dir == "down" && ecs->getDownRequests()->contains(floorNum)) {
        ecs->getDownRequests()->remove(floorNum);
        ecs->getFloors()->at(floorNum - 1).serviced(dir);
        ecs->getElevators()->at(carNum - 1).setCameFromFloorReq(true);
        ecs->getElevators()->at(carNum - 1).stop();
    }
    //handle car request
    else if (ecs->getCarRequests()->values(carNum).contains(floorNum)) {
        ecs->getCarRequests()->remove(carNum, floorNum);
        std::cout << "Destination button for floor " << floorNum << " turns off" << std::endl;
        ecs->updateFloorDisplay(floorNum);
        ecs->getElevators()->at(carNum - 1).setFloorNum(floorNum);
        ecs->getElevators()->at(carNum - 1).stop();
        ecs->getElevators()->at(carNum - 1).setIdle();
    }
    //handles edges cases of halting and stopping at the 1st floor
    else if(floorNum == 1 || ecs->getElevators()->at(carNum - 1).isOperationHalted()) {
        ecs->getElevators()->at(carNum - 1).stop();
        ecs->getElevators()->at(carNum - 1).setIdle();
    }
    //continue moving
    else {
        ecs->updateFloorDisplay(floorNum);
        ecs->getElevators()->at(carNum - 1).setFloorNum(floorNum);
        ecs->getElevators()->at(carNum - 1).start(dir);
    }
}

void Opportunistic::floorRequest(const QString& dir, int floorNum) {
    if (dir == "up") {
        ecs->getUpRequests()->insert(floorNum);
    }
    else if (dir == "down") {
        ecs->getDownRequests()->insert(floorNum);
    }
    if (ecs->moveIdle(dir, floorNum)) {
        for(int i = 0;i < ecs->getNumElevators();++i) {
            if(ecs->getElevators()->at(i).isIdle()) {
                ecs->getElevators()->at(i).start(dir);
                return;
            }
        }
    }
}

void Opportunistic::carRequest(int carNum, int floorNum) {
    //if the current car request already exists don't add it again (important since type is multiMap)
    if (!ecs->getCarRequests()->values().contains(floorNum)) {
        ecs->getCarRequests()->insert(carNum, floorNum);
        std::cout << "Destination button for floor " << floorNum << " illuminates" << std::endl;
    }

    //if the elevator door isn't closed at the time of the request send another in 10 seconds
    if (ecs->getElevators()->at(carNum - 1).isDoorOpen()) {
        QTimer::singleShot(10000, ecs->getMainWindow(), &MainWindow::pressDestinationButton);
    }
    else {
        ecs->readyToMove(carNum);
    }
}



