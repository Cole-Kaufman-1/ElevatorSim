#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QString>
#include "Display.h"
#include "Door.h"
#include "FloorButtons.h"
#include "DestinationButton.h"
#include "CloseDoorButton.h"
#include "OpenDoorButton.h"
#include "HelpButton.h"
#include "FireButton.h"
#include "ECS.h"

class ECS;
class FloorButtons;
class DestinationButton;
class Display;
class Door;
class CloseDoorButton;
class OpenDoorButton;
class FireButton;
class HelpButton;

class Elevator : public QObject {
    public:
        explicit Elevator(QObject *parent = nullptr);
        Elevator(ECS* ecs);
        ~Elevator();


        void stop();
        void start(QString direction);
        void newFloor(int floorNum);
        void carRequest(int floorNum);
        void openRequest();
        void closeRequest();
        void outputFireEvent();
        void outputDoorObstructed();
        void outputOverload();
        void outputPowerOutage();


    protected:
        static int nextElevatorNum;

    private:
        int carNum;
        int floorNum;
        QString direction;
        bool idle;
        Display* display;
        Door* door;
        FloorButtons* floorButton;
        DestinationButton* destButton;
        CloseDoorButton* closeDoorButton;
        OpenDoorButton* openDoorButton;
        HelpButton* helpButton;
        FireButton* fireButton;
        ECS* theECS;
        Q_OBJECT

};

#endif
