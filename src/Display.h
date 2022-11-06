#ifndef DISPLAY_H
#define DISPLAY_H

#include "Elevator.h"

class Elevator;

class Display {
    public:
        Display(Elevator* elevator);
        //void update(QString msg);
    private:
        QString displayMsg;
        Elevator *elevator;
};

#endif
