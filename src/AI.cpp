#include "AI.h"
#include <algorithm>

AI::AI(ECS* ecs): ecs(ecs) {}

//makes a decision when an elevator is about to arrive at a new floor
void AI::makeDecision(int floorNum, int carNum, const QString& dir) {
    //define temporary vector for readability and conciseness
    std::vector<int>* tempVisit = ecs->getElevators()->at(carNum - 1).getFloorsToVisit();
    //if the elevator is headed up, the floorNum is in the elevators list of floors to visit and it's in  up requests
    if (dir == "up" && contains(tempVisit, floorNum) && ecs->getUpRequests()->contains(floorNum)) {
        //serviced floor request remove it from list of floors to visit
        remove(ecs->getElevators()->at(carNum - 1).getFloorsToVisit(), floorNum);
        ecs->getUpRequests()->remove(floorNum);
        ecs->getFloors()->at(floorNum - 1).serviced(dir);
        ecs->getElevators()->at(carNum - 1).setCameFromFloorReq(true);
        ecs->getElevators()->at(carNum - 1).stop();
    }
    //if the elevator is headed down and the floorNum is in the elevators list of floors to visit and it in down requests
    else if (dir == "down" && contains(tempVisit, floorNum) && ecs->getDownRequests()->contains(floorNum)) {
        //serviced floor request remove it from list of floors to visit
        remove(ecs->getElevators()->at(carNum - 1).getFloorsToVisit(), floorNum);
        ecs->getDownRequests()->remove(floorNum);
        ecs->getFloors()->at(floorNum - 1).serviced(dir);
        ecs->getElevators()->at(carNum - 1).setCameFromFloorReq(true);
        ecs->getElevators()->at(carNum - 1).stop();
    }
    //service car request
    else if(contains(tempVisit, floorNum)) {
        //serviced car request emove it from list of floors to visit
        remove(ecs->getElevators()->at(carNum - 1).getFloorsToVisit(), floorNum);
        std::cout << "Destination button for floor " << floorNum << " turns off" << std::endl;
        ecs->updateFloorDisplay(floorNum);
        ecs->getElevators()->at(carNum - 1).setFloorNum(floorNum);
        ecs->getElevators()->at(carNum - 1).stop();
        ecs->getElevators()->at(carNum - 1).setIdle();
    }
    //stop the elevator if it's at the first floor or an emergency button has been pressed
    else if(floorNum == 1 || ecs->getElevators()->at(carNum - 1).isOperationHalted()) {
        ecs->getElevators()->at(carNum - 1).stop();
        ecs->getElevators()->at(carNum - 1).setIdle();
    }
    //continue to next floor
    else {
        ecs->updateFloorDisplay(floorNum);
        ecs->getElevators()->at(carNum - 1).setFloorNum(floorNum);
        ecs->getElevators()->at(carNum - 1).start(dir);
    }

}

//remove first occurence of an item, sufficient since we only add unique items to this vector (could have used set but existing code works around vector)
void AI::remove(std::vector<int>* vector, const int item) {
    vector->erase(std::remove(vector->begin(), vector->end(), item));
}

// std::find returns the element if found and an iterator to end if not
// this provides and easier way to understand what's happening in each function of this class
bool AI::contains(std::vector<int>* vector, const int item) {
    if (std::find(vector->begin(), vector->end(), item) != vector->end()) {
        return true;
    }
    return false;
}

//creates a floor request and floor to visit for elevator upon receiving a floor request
void AI::floorRequest(const QString& dir, int floorNum) {
    if (dir == "up") {
        ecs->getUpRequests()->insert(floorNum);
        //used zero for TA testing purposes if visually testing multiple elevators this could be modified to use a dynamic index
        ecs->getElevators()->at(0).getFloorsToVisit()->push_back(floorNum);
    }
    else {
        ecs->getDownRequests()->insert(floorNum);
        //used zero for TA testing purposes if visually testing multiple elevators this could be modified to use a dynamic index
        ecs->getElevators()->at(0).getFloorsToVisit()->push_back(floorNum);
    }
    //checks if an idle elevator needs to be moved
    if (ecs->moveIdle(dir, floorNum)) {
        for(int i = 0;i < ecs->getNumElevators();++i) {
            if(ecs->getElevators()->at(i).isIdle()) {
                ecs->getElevators()->at(i).getFloorsToVisit()->push_back(floorNum);
                ecs->getElevators()->at(i).start(dir);
                return;
            }
        }
    }
}

//creates a new floor to visit for an elevator upon receiving a car request
void AI::carRequest(int carNum, int floorNum) {
    //if the current car already has the floor in floorsToVisit don't add it again (important since type is vector)
    std::vector<int>* tempVisit = ecs->getElevators()->at(carNum - 1).getFloorsToVisit();
    if (!contains(tempVisit, floorNum)) {
        tempVisit->push_back(floorNum);
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

