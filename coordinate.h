#pragma once

#include <vector>

class Coordinate {
public:
    Coordinate(int x, int y, int z);
    int x, y, z;
};

std::vector<Coordinate> get_manhatten_coordinates(int x, int y, int z);