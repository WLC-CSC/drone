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
            pitch = std::stoi(value);
        } else if (key == "roll") {
            roll = std::stoi(value);
        } else if (key == "yaw") {
            yaw = std::stoi(value);
        } else if (key == "vgx") {
            speed_x = std::stoi(value);
        } else if (key == "vgy") {
            speed_y = std::stoi(value);
        } else if (key == "vgz") {
            speed_z = std::stoi(value);
        } else if (key == "templ") {
            lowest_temp = std::stoi(value);
        } else if (key == "temph") {
            highest_temp = std::stoi(value);
        } else if (key == "tof") {
            time_of_flight = std::stoi(value);
        } else if (key == "h") {
            height = std::stoi(value);
        } else if (key == "bat") {
            battery = std::stoi(value);
        } else if (key == "baro") {
            barometer = std::stod(value);
        } else if (key == "time") {
            time = std::stoi(value);
        } else if (key == "agx") {
            acceleration_x = std::stod(value);
        } else if (key == "agy") {
            acceleration_y = std::stod(value);
        } else if (key == "agz") {
            acceleration_z = std::stod(value);
        }
    }
}

std::string StateData::get_state() {
    return "Pitch: " + std::to_string(pitch) + " Roll: " + std::to_string(roll) +
           " Yaw: " + std::to_string(yaw) +
           " Speed X: " + std::to_string(speed_x) +
           " Speed Y: " + std::to_string(speed_y) +
           " Speed Z: " + std::to_string(speed_z) +
           " Lowest Temperature: " + std::to_string(lowest_temp) +
           " Highest Temperature: " + std::to_string(highest_temp) +
           " Time of Flight: " + std::to_string(time_of_flight) +
           " Height: " + std::to_string(height) +
           " Battery: " + std::to_string(battery) +
           " Barometer: " + std::to_string(barometer) +
           " Time: " + std::to_string(time) +
           " Acceleration X: " + std::to_string(acceleration_x) +
           " Acceleration Y: " + std::to_string(acceleration_y) +
           " Acceleration Z: " + std::to_string(acceleration_z);
}