#include "navigations.h"

#include <cmath>
#include <stdexcept>

#include "coordinate.h"

void fly_manhatten_xyz(Drone drone, int x, int y, int z) {
    std::vector<Coordinate> path = get_manhatten_coordinates(x, y, z);
    for (auto [x, y, z] : path) {
        if (x < 0) {
            drone.left(abs(x));
        } else if (x >= 0) {
            drone.right(abs(x));
        }

        if (y < 0) {
            drone.down(abs(y));
        } else if (y >= 0) {
            drone.up(abs(y));
        }

        if (z < 0) {
            drone.backward(abs(z));
        } else if (z >= 0) {
            drone.forward(abs(z));
        }
    }
}

void fly_xyz(Drone drone, int x, int y, int z) {
    std::vector<Coordinate> path = get_coordinates(x, y, z);
    for (auto [x, y, z] : path) {
        if (x < 0) {
            drone.send_and_receive("left" + std::to_string(abs(x)));
        } else if (x >= 0) {
            drone.right(abs(x));
        }

        if (y < 0) {
            drone.down(abs(y));
        } else if (y >= 0) {
            drone.up(abs(y));
        }

        if (z < 0) {
            drone.backward(abs(z));
        } else if (z >= 0) {
            drone.forward(abs(z));
        }
    }
}