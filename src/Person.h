#ifndef PERSON_H
#define PERSON_H

class Person {
    public:
        Person();
        void pressDestButton(int floorNum);
        void pressFloorButton(int direction);
        void pressOpenButton();
        void pressCloseButton();
        void pressHelpButton();
        void pressFireButton();
    private:
        int currentFloor;
        int inCarNum;
};

#endif
