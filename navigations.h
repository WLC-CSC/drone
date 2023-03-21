#pragma once
#include <string>

#include "drone.h"

class Navigations {
public:
    Navigations();
    void lower_bound_check(int value, int lower_bound);
    // Navigation Commands
    void go_manhatten_xyz(int x, int y, int z);
    void go_xyz(int x, int y, int z);

private:
    Drone drone;
    int value;
    int lower_bound;
    int upper_bound;
    int x;
    int y;
    int z;
};