#ifndef ECS_H
#define ECS_H

#include <vector>
#include <map>
#include <string>
#include "Elevator.h"
#include "IStrategy.h"

class ECS  {
    public:
        ECS(int numElevators, int numFloors);
        std::map<int, std::string> getRequests();
        std::vector<Elevator> getElevators();

        void floorRequest(const std::string& dir, int floorNum);
        void newFloor(int floorNum, int carNum);
        void carRequest(int carNum, int floorNum);
        void readyToMove(int carNum);
        void changeStrategy();
        void handleHelp(int floorNum, int carNum);
        void handleFire(int floorNum, int carNum);
        void handleOverload(int floorNum, int carNum);
        void handlePowerOutage(int floorNum, int carNum);

    private:
        std::vector<Elevator> elevators;
        std::vector<Floor> floors;
        std::map<int, std::string> FloorRequests;
        std::map<int, int> carRequests;
        int numElevators;
        int numFloors;
        IStrategy* currentStrategy;
        std::vector<IStrategy> strategies;

};

#endif