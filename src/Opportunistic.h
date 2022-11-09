#ifndef OPPORTUNISTIC_H
#define OPPORTUNISTIC_H

#include "IStrategy.h"
#include "ECS.h"

class Opportunistic : public IStrategy {
    public:
        Opportunistic(ECS* ecs);
        void makeDecision(int floorNum, int carNum, const QString& dir);

    private:
        ECS* ecs;
};

#endif
