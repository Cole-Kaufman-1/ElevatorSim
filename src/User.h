#ifndef USER_H
#define USER_H

class User {
    public:
        User(int currentFloor=1);
        bool inElevator();

        int getFloor();
        int getCarNum();

        void setFloor(int num);
        void setCarNum(int num);

    private:
        int currentFloor;
        int inCarNum;
};

#endif
