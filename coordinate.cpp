#include "coordinate.h"

#include <algorithm>
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

std::vector<Coordinate> get_coordinates(int x, int y, int z) {
    std::vector<Coordinate> path;
    int next_x = 0;
    int next_y = 0;
    int next_z = 0;
    double x_multiplier = 0.0;
    double y_multiplier = 0.0;
    double z_multiplier = 0.0;
    while (x != 0 || y != 0 || z != 0) {
        int iterations = ((std::min({abs(x), abs(y), abs(z)})) / 20) + 1;

        if (abs(x) < abs(y) && abs(x) < abs(z)) {
            x_multiplier = 1;
            y_multiplier = abs(y) / abs(x);
            z_multiplier = abs(z) / abs(x);
        } else if (abs(y) < abs(x) && abs(y) < abs(z)) {
            y_multiplier = 1;
            x_multiplier = abs(x) / abs(y);
            z_multiplier = abs(z) / abs(y);
        } else if (abs(z) < abs(y) && abs(z) < abs(x)) {
            z_multiplier = 1;
            y_multiplier = abs(y) / abs(z);
            x_multiplier = abs(x) / abs(z);
        }

        if (abs(x) < 40) {
            next_x = x;
            x = 0;
        } else {
            next_x = 20 * x_multiplier;
            x -= next_x;
        }
        if (abs(y) < 40) {
            next_y = y;
            y = 0;
        } else {
            next_y = 20 * y_multiplier;
            y -= next_y;
        }
        if (abs(z) < 40) {
            next_z = z;
            z = 0;
        } else {
            next_z = 20 * z_multiplier;
            z -= next_z;
        }

        Coordinate coordinate(next_x, next_y, next_z);
        next_x = 0;
        next_y = 0;
        next_z = 0;
        path.push_back(coordinate);
    }
    return path;
}
