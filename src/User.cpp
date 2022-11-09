#include "User.h"

User::User(int c): currentFloor(c), inCarNum(0){}

bool User::inElevator() const {
    if (inCarNum > 0) {
        return true;
    }
}

int User::getFloor() const {
    return currentFloor;
}

int User::getCarNum() const{
    return inCarNum;
}

void User::setFloor(int num) {
    currentFloor = num;
}

void User::setCarNum(int num) {
    inCarNum = num;
}
