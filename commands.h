#pragma once
#include <string>

class Commands {
public:
    std::string command();
    std::string takeoff();
    std::string land();
    std::string emergency();
    std::string stop();
    std::string up(int distance);
    std::string down(int distance);
    std::string left(int distance);
    std::string right(int distance);
    std::string forward(int distance);
    std::string backward(int distance);
    std::string clockwise(int degrees);
    std::string counter_clockwise(int degrees);
    std::string xyz(int x, int y, int z);
    std::string manhattan_xyz(int x, int y, int z);
    std::string speed(int speed);

private:
};