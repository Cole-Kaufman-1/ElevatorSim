#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include "Elevator.h"

class Display {
    public:
        Display();
        void update(const std::string& msg);
    private:
        std::string displayMsg;
        Elevator* elevator;
};

#endif