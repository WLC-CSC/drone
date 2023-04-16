#pragma once
#include <string>

class StateData {
public:
    StateData(std::string state_info);
    std::string get_state();

    int pitch;
    int roll;
    int yaw;
    int speed_x;
    int speed_y;
    int speed_z;
    int lowest_temp;
    int highest_temp;
    int time_of_flight;
    int height;
    int battery;
    double barometer;
    int time;
    double acceleration_x;
    double acceleration_y;
    double acceleration_z;
};