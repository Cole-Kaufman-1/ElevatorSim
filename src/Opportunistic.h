#ifndef OPPORTUNISTIC_H
#define OPPORTUNISTIC_H

#include "IStrategy.h"
#include "ECS.h"

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
 */

class Opportunistic : public IStrategy {
    public:
        Opportunistic(ECS* ecs);
        void makeDecision(int floorNum, int carNum, const QString& dir);
        void floorRequest(const QString& dir, int floorNum);
        void carRequest(int carNum, int floorNum);

    private:
        ECS* ecs;
};

#endif
