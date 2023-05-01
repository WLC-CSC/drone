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
            continue;
        } else if (abs(x) >= 500) {
            if (x > 0) {
                next_x = 400;
                x -= 400;
            } else if (x < 0) {
                next_x = -400;
                x += 400;
            }
            continue;
        } else if (abs(x) >= 20 && abs(x) < 500) {
            if (x > 0) {
                next_x = x - (x % 20);
                if ((x % 20) < 20 && (x % 20) > 0) {
                    x -= (x % 20);
                    next_x += (x % 20);
                } else {
                    x -= next_x;
                }
            }
            continue;
        }

        if (abs(y) >= 520) {
            if (y > 0) {
                next_y = 500;
                y -= 500;
            } else if (y < 0) {
                next_y = -500;
                y += 500;
            }
            continue;
        } else if (abs(y) >= 500) {
            if (y > 0) {
                next_y = 400;
                y -= 400;
            } else if (y < 0) {
                next_y = -400;
                y += 400;
            }
            continue;
        } else if (abs(y) >= 20 && abs(y) < 500) {
            if (y > 0) {
                next_y = y - (y % 20);
                if ((y % 20) < 20 && (y % 20) > 0) {
                    y -= (y % 20);
                    next_y += (y % 20);
                } else {
                    y -= next_y;
                }
            }
            continue;
        }

        if (abs(z) >= 520) {
            if (z > 0) {
                next_z = 500;
                z -= 500;
            } else if (z < 0) {
                next_z = -500;
                z += 500;
            }
            continue;
        } else if (abs(z) >= 500) {
            if (z > 0) {
                next_z = 400;
                z -= 400;
            } else if (z < 0) {
                next_z = -400;
                z += 400;
            }
            continue;
        } else if (abs(z) >= 20 && abs(z) < 500) {
            if (z > 0) {
                next_z = z - (z % 20);
                if ((z % 20) < 20 && (z % 20) > 0) {
                    z -= (z % 20);
                    next_z += (z % 20);
                } else {
                    z -= next_z;
                }
            }
            continue;
        }

        Coordinate coordinate(next_x, next_y, next_z);
        next_x = 0;
        next_y = 0;
        next_z = 0;
        path.push_back(coordinate);
    }

    return path;
}