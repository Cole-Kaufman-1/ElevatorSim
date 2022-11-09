#ifndef ISTRATEGY_H
#define ISTRATEGY_H
#include <QString>

class IStrategy {
    public:
        virtual ~IStrategy() = default;
        virtual void makeDecision(int floorNum, int carNum, const QString& dir) = 0;
};

#endif
