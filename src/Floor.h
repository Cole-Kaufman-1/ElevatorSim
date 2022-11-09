#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>
#include <QString>
#include "ECS.h"

class ECS;

class Floor {
    public:
        Floor(ECS* ecs, int maxFloor);
        void serviced(const QString& dir);
        int getFloorNum();
        void pressUp();
        void pressDown();

    private:
        int floorNum;
        int maxFloor;
        bool upWaiting;
        bool downWaiting;
        static int nextFloorID;
        ECS* ecs;
        void turnOffUp();
        void turnOffDown();
};

#endif
