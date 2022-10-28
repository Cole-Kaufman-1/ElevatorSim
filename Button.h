#ifndef BUTTON_H
#define BUTTON_H

class Button {
    public:
        virtual void press() = 0;
        virtual void turnOff() = 0;
        virtual void turnOn() = 0;
        virtual ~Button();
    private:
    bool on;

};
#endif