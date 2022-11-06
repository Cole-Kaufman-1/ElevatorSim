#ifndef USER_H
#define USER_H

class User {
    public:
        User();
        ~User();
        bool inElevator();

    private:
        int currentFloor;
        int inCarNum;
};

#endif
