#ifndef SPEAKER_H
#define SPEAKER_H


#include <string>
#include "Elevator.h"

class Speaker {
    public:
        Speaker();
        void outputMessage(const std::string& msgType);
        void ringBell();
        void getHelp();
    private:
        std::string displayMsg;
        Elevator* elevator;
};

#endif
