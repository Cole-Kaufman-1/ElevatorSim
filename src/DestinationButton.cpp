#include "DestinationButton.h"

DestinationButton::DestinationButton(Elevator *elevator): elevator(elevator) {
    selectedFloor = 0;
}

void DestinationButton::press(int num){
    selectedFloor = num;
    on = true;
}

