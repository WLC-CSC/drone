#include "navigations.h"

#include <cmath>
#include <stdexcept>

void Navigations::lower_bound_check(int value, int lower_bound) {
    if (value < lower_bound) {
        throw std::runtime_error(
            "Value cannot be lower than the absolute value of " +
            std::to_string(lower_bound));
    }
}

void Navigations::go_manhatten_xyz(int x, int y, int z) {
    int abs_x = abs(x);
    int abs_y = abs(y);
    int abs_z = abs(z);

    lower_bound_check(abs_x, 20);
    lower_bound_check(abs_y, 20);
    lower_bound_check(abs_z, 20);

    std::string x_translation;
    if (x >= 20) {
        x_translation = "right ";
    } else {
        x_translation = "left ";
    }
    std::string y_translation;
    if (y >= 20) {
        y_translation = "up ";
    } else {
        y_translation = "down ";
    }
    std::string z_translation;
    if (z >= 20) {
        z_translation = "forward ";
    } else {
        z_translation = "backward ";
    }

    int remaining_z_value = abs_z;
    while (remaining_z_value != 0) {
        if (remaining_z_value > 520) {
            drone.send_and_receive(z_translation + std::to_string(500));
            remaining_z_value -= 500;
        } else if (remaining_z_value > 500) {
            drone.send_and_receive(z_translation + std::to_string(480));
            remaining_z_value -= 480;
        } else {
            drone.send_and_receive(z_translation +
                                   std::to_string(remaining_z_value));
            remaining_z_value -= remaining_z_value;
        }
    }

    int remaining_x_value = abs_x;
    while (remaining_x_value != 0) {
        if (remaining_x_value > 520) {
            drone.send_and_receive(x_translation + std::to_string(500));
            remaining_x_value -= 500;
        } else if (remaining_x_value > 500) {
            drone.send_and_receive(x_translation + std::to_string(480));
            remaining_x_value -= 480;
        } else {
            drone.send_and_receive(x_translation +
                                   std::to_string(remaining_x_value));
            remaining_x_value -= remaining_x_value;
        }
    }

    int remaining_y_value = abs_y;
    while (remaining_y_value != 0) {
        if (remaining_y_value > 520) {
            drone.send_and_receive(y_translation + std::to_string(500));
            remaining_y_value -= 500;
        } else if (remaining_y_value > 500) {
            drone.send_and_receive(y_translation + std::to_string(480));
            remaining_y_value -= 480;
        } else {
            drone.send_and_receive(y_translation +
                                   std::to_string(remaining_y_value));
            remaining_y_value -= remaining_y_value;
        }
    }
}

void Navigations::go_xyz(int x, int y, int z) {
    int abs_x = abs(x);
    int abs_y = abs(y);
    int abs_z = abs(z);

    lower_bound_check(abs_x, 20);
    lower_bound_check(abs_y, 20);
    lower_bound_check(abs_z, 20);

    std::string x_translation;
    if (x >= 20) {
        x_translation = "right ";
    } else {
        x_translation = "left ";
    }
    std::string y_translation;
    if (y >= 20) {
        y_translation = "up ";
    } else {
        y_translation = "down ";
    }
    std::string z_translation;
    if (z >= 20) {
        z_translation = "forward ";
    } else {
        z_translation = "backward ";
    }

    if (z >= 40) {
        int first_z_movement = 20 + (x % 20);
        drone.send_and_receive(z_translation +
                               std::to_string(first_z_movement));
    } else {
        drone.send_and_receive(z_translation + std::to_string(z));
    }
    if (x >= 40) {
        int first_x_movement = 20 + (x % 20);
        drone.send_and_receive(x_translation +
                               std::to_string(first_x_movement));
    } else {
        drone.send_and_receive(x_translation + std::to_string(x));
    }
    if (y >= 40) {
        int first_y_movement = 20 + (x % 20);
        drone.send_and_receive(y_translation +
                               std::to_string(first_y_movement));
    } else {
        drone.send_and_receive(y_translation + std::to_string(y));
    }
    while (x != 0 || y != 0 || z != 0) {
        int remaining_x = x;
        int remaining_y = y;
        int remaining_z = z;

        if (remaining_z != 0) {
            drone.send_and_receive(z_translation + "20");
        }
        if (remaining_x != 0) {
            drone.send_and_receive(x_translation + "20");
        }
        if (remaining_y != 0) {
            drone.send_and_receive(y_translation + "20");
        }
    }
}