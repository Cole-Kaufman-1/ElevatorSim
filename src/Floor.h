#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>
#include <QString>
#include "ECS.h"

/* Class Purpose: An floor objects for a user to arrive at, passes information to the ECS and recieves floor button calls
 *
 * Data Members:
 * -ECS* ecs: a pointer to the ECS object
 * -floorNum: number of current floor
 * -maxFloor: number of highest floor
 * -upWaiting: indicates if the up button on a floor is on
 * -downWaiting: indicates if the down button on a floor is on
 * -static int nextFloorID: used in numbering floors upon creation
 *
 * Class Functions:
 * Getters for floorNum
 *
 * +void serviced(const QString& dir): informs the ECS a floor has been serviced
 * +void pressUp(): turns the upWaiting bool to true
 * +void pressDown(): turns the downWaiting bool to true
 * -void turnOffUp(): turns the upWaiting bool to false
 * -void turnOffDown: turns the downWaiting bool to false
 */

class ECS;

class Floor {
    public:
        Floor(ECS* ecs, int maxFloor);
        void serviced(const QString& dir);
        int getFloorNum();
        void pressUp();
        void pressDown();

    private:
        ECS* ecs;
        int floorNum;
        int maxFloor;
        bool upWaiting;
        bool downWaiting;
        static int nextFloorID;
        void turnOffUp();
        void turnOffDown();
};

#endif
