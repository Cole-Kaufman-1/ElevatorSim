#ifndef AI_H
#define AI_H

#include "IStrategy.h"

class AI : public IStrategy {
    public:
        AI();
        void makeDecision(int floorNum, int carNum, const QString& dir);

};

#endif
