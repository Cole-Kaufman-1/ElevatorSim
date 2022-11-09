#ifndef AI_H
#define AI_H

#include "IStrategy.h"
#include "ECS.h"
#include <vector>

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
