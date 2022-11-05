#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include "Display.h"
#include "Speaker.h"
#include "Door.h"
#include "FloorSensor.h"
#include "FloorButton.h"
#include "DestinationButton.h"
#include "CloseDoorButton.h"
#include "OpenDoorButton.h"
#include "HelpButton.h"
#include "FireButton.h"

class Elevator {
    public:
        Elevator();
        void stop();
        void start(const std::string& direction);
        void newFloor(int floorNum);
        void carRequest(int floorNum);
        void openRequest();
        void closeRequest();
        void outputFireEvent();
        void outputDoorObstructed();
        void outputOverload();
        void outputPowerOutage();
        //yet to decide on constants for display messages and speaker messages 

    private:
        int carNum;
        int floorNum;
        std::string direction;
        bool idle;
        Display* display;
        Speaker* speaker;
        Door* door;
        FloorSensor* floorSensor;
        FloorButton* floorButton;
        DestinationButton* destButton;
        CloseDoorButton* closeDoorButton;
        OpenDoorButton* openDoorButton;
        HelpButton* helpButton;
        FireButton* fireButton;

};

#endif