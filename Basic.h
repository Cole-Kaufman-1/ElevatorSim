#ifndef BASIC_H
#define BASIC_H

#include "IStrategy.h"

class Basic : public IStrategy {
    public:
        void executeStrategy();
    private:
        void makeDecision(int floorNum, int carNum);
        void moveIdle(int floorNum, int carNum); 
};

#endif