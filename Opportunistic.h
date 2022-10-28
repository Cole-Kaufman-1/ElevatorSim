#ifndef OPPORTUNISTIC_H
#define OPPORTUNISTIC_H

#include "IStrategy.h"

class Opportunistic : public IStrategy {
    public:
        void executeStrategy();
    private:
        void makeDecision(int floorNum, int carNum);
        void moveIdle(int floorNum, int carNum);
};

#endif