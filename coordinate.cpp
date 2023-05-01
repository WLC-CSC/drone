#include "coordinate.h"

#include <cmath>

Coordinate::Coordinate(int x, int y, int z) : x{x}, y{y}, z{z} {}

std::vector<Coordinate> get_manhatten_coordinates(int x, int y, int z) {
    std::vector<Coordinate> path;
    int next_x = 0;
    int next_y = 0;
    int next_z = 0;

    while (x != 0 || y != 0 || z != 0) {
        if (abs(x) >= 520) {
            if (x > 0) {
                next_x = 500;
                x -= 500;
            } else if (x < 0) {
                next_x = -500;
                x += 500;
            }
        } else if (abs(x) >= 500) {
            if (x > 0) {
                next_x = 400;
                x -= 400;
            } else if (x < 0) {
                next_x = -400;
                x += 400;
            }
        } else if (abs(x) >= 40) {
            if (x < 0) {
                next_x = x + 20;
                x = -20;
            } else {
                next_x = x - 20;
                x = 20;
            }
        } else {
            next_x = x;
            x = 0;
        }

        if (abs(y) >= 520) {
            if (y > 0) {
                next_y = 500;
                y -= 500;
            } else if (y < 0) {
                next_y = -500;
                y += 500;
            }
        } else if (abs(y) >= 500) {
            if (y > 0) {
                next_y = 400;
                y -= 400;
            } else if (y < 0) {
                next_y = -400;
                y += 400;
            }
        } else if (abs(y) >= 40) {
            if (y < 0) {
                next_y = y + 20;
                y = -20;
            } else {
                next_y = y - 20;
                y = 20;
            }
        } else {
            next_y = y;
            y = 0;
        }

        if (abs(z) >= 520) {
            if (z > 0) {
                next_z = 500;
                z -= 500;
            } else if (z < 0) {
                next_z = -500;
                z += 500;
            }
        } else if (abs(z) >= 500) {
            if (z > 0) {
                next_z = 400;
                z -= 400;
            } else if (z < 0) {
                next_z = -400;
                z += 400;
            }
        } else if (abs(z) >= 40) {
            if (z < 0) {
                next_z = z + 20;
                z = -20;
            } else {
                next_z = z - 20;
                z = 20;
            }
        } else {
            next_z = z;
            z = 0;
        }

        Coordinate coordinate(next_x, next_y, next_z);
        next_x = 0;
        next_y = 0;
        next_z = 0;
        path.push_back(coordinate);
    }

    return path;
}