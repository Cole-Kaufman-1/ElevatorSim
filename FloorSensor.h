#ifndef FLOOR_SENSOR_H
#define FLOOR_SENSOR_H

class FloorSensor {
    public:
        FloorSensor();
        void floorDetected(int floorNum);
    private:
        Elevator* elevator;
};

#endif