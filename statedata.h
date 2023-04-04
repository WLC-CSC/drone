#pragma once
#include <string>

class StateData {
public:
    StateData(std::string state_info);
    std::string get_state();

    std::string pitch;
    std::string roll;
    std::string yaw;
    std::string speed_x;
    std::string speed_y;
    std::string speed_z;
    std::string lowest_temp;
    std::string highest_temp;
    std::string time_of_flight;
    std::string height;
    std::string battery;
    std::string barometer;
    std::string time;
    std::string acceleration_x;
    std::string acceleration_y;
    std::string acceleration_z;
};