#include "User.h"

User::User(int c): currentFloor(c), inCarNum(0){}

bool User::inElevator() {
    if (inCarNum > 0) return true;
}

int User::getFloor() {
    return currentFloor;
}

int User::getCarNum() {
    return inCarNum;
}

void User::setFloor(int num) {
    currentFloor = num;
}

void User::setCarNum(int num) {
    inCarNum = num;
}
