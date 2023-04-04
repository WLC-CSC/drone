#include "statedata.h"

#include <sstream>

StateData::StateData(std::string state_info) {
    std::stringstream ss(state_info);
    std::string token;
    std::string result;
    std::string key;
    std::string value;
    while (std::getline(ss, token, ';')) {
        std::stringstream token_ss(token);
        std::getline(token_ss, key, ':');
        std::getline(token_ss, value, ':');
        if (key == "pitch") {
            pitch += "Pitch: " + value + " ";
        } else if (key == "roll") {
            roll += "Roll: " + value + " ";
        } else if (key == "yaw") {
            yaw += "Yaw: " + value + " ";
        } else if (key == "vgx") {
            speed_x += "Speed X: " + value + " ";
        } else if (key == "vgy") {
            speed_y += "Speed Y: " + value + " ";
        } else if (key == "vgz") {
            speed_z += "Speed Z: " + value + " ";
        } else if (key == "templ") {
            lowest_temp += "Lowest Temperature: " + value + " ";
        } else if (key == "temph") {
            highest_temp += "Highest Temperature: " + value + " ";
        } else if (key == "tof") {
            time_of_flight += "Time of Flight: " + value + " ";
        } else if (key == "h") {
            height += "Height: " + value + " ";
        } else if (key == "bat") {
            battery += "Battery: " + value + " ";
        } else if (key == "baro") {
            barometer += "Barometer: " + value + " ";
        } else if (key == "time") {
            time += "Time: " + value + " ";
        } else if (key == "agx") {
            acceleration_x += "Acceleration X: " + value + " ";
        } else if (key == "agy") {
            acceleration_y += "Acceleration Y: " + value + " ";
        } else if (key == "agz") {
            acceleration_z += "Acceleration Z: " + value + " ";
        }
    }
}

std::string StateData::get_state() {
    return pitch + roll + yaw + speed_x + speed_y + speed_z + lowest_temp +
           highest_temp + time_of_flight + height + battery + barometer + time +
           acceleration_x + acceleration_y + acceleration_z;
}