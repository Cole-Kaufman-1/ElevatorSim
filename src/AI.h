#ifndef AI_H
#define AI_H

#include "IStrategy.h"
#include "ECS.h"
#include <vector>

/* Class Purpose: An allocation strategy for elevator operation
 *
 * Data Members:
 * -ECS* ecs: a pointer to the ECS object
 *
 * Class Functions:
 *
 * void makeDecision(int floorNum, int carNum, const QString& dir): makes a decision about what the elevator should do when approaching a new floor.
 * void floorRequest(const QString& dir, int floorNum): handles incoming requests from passengers on a floor
 * void carRequest(int carNum, int floorNum): handles incoming requests from passengers in an elevator
 *
 * void remove(std::vector<int>* vector, const int item): a helper function to be used inside AI.cpp, cleans up code and concisely removes and element from a vector
 * bool contains(std::vector<int>* vector, const int item): a helper function to be used inside AI.cpp, cleans up code and concisely checks if a vector contains an item
 */


class AI : public IStrategy {
    public:
        AI(ECS* ecs);
        void makeDecision(int floorNum, int carNum, const QString& dir);
        void floorRequest(const QString& dir, int floorNum);
        void carRequest(int carNum, int floorNum);


    private:
        ECS* ecs;
        void remove(std::vector<int>* vector, const int item);
        bool contains(std::vector<int>* vector, const int item);
};

#endif
