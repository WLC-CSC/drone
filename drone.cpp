#include "drone.h"

#include <cmath>
#include <iostream>

void Drone::send_and_receive(std::string command) {
    socket.send(command);
    std::cout << socket.recv() << '\n';
}

void Drone::handle_int_values(std::string command, int lower_bound,
                              int upper_bound, int value) {
    if (value > lower_bound) {
        std::cerr << "Distance must be greater than or equal to 20cm\n";
    } else if (value <= upper_bound) {
        send_and_receive(command + std::to_string(value));
    } else if (value > upper_bound) {
        int iterations = (value / upper_bound);
        int remaining = (distance % upper_bound);
        if (remaining < lower_bound) {
            remaining += upper_bound;
            for (int i = 0; i < (iterations - 1); i++) {
                send_and_receive(command + " " + std::to_string(upper_bound));
            }
            send_and_receive(command + " " + std::to_string(remaining / 2));
            send_and_receive(command + " " + std::to_string(remaining / 2));
        } else {
            for (int i = 0; i < iterations; i++) {
                send_and_receive(command + " " + std::to_string(upper_bound));
            }
            send_and_receive(command + " " + std::to_string(remaining));
        }
    } else {
        std::cerr << "Value error for " + command + " value";
    }
}

Drone::Drone() : socket{ip, port} {
    socket.send("command");
    std::cout << socket.recv() << '\n';
}

void Drone::takeoff() {
    send_and_receive("takeoff");
}

void Drone::land() {
    send_and_receive("land");
}

void Drone::flip(char direction) {
    send_and_receive("flip " + std::to_string(direction));  // l, r, f, b
}

void Drone::emergency() {
    send_and_receive("emergency");
}

void Drone::stop() {
    send_and_receive("stop");
}

void Drone::up(int distance) {
    handle_int_values("up", 20, 500, distance);
}

void Drone::down(int distance) {
    handle_int_values("down", 20, 500, distance);
}

void Drone::left(int distance) {
    handle_int_values("left", 20, 500, distance);
}

void Drone::right(int distance) {
    handle_int_values("right", 20, 500, distance);
}

void Drone::forward(int distance) {
    handle_int_values("forward", 20, 500, distance);
}

void Drone::backward(int distance) {
    handle_int_values("backward", 20, 500, distance);
}

void Drone::clockwise(int degrees) {
    handle_int_values("cw", 1, 360, degrees);
}

void Drone::counter_clockwise(int degrees) {
    handle_int_values("ccw", 1, 360, degrees);
}

void Drone::change_speed(int speed) {
    if (speed > 10) {
        std::cerr << "Speed must be greater than or equal to 10cm/s";
    } else if (speed <= 100) {
        send_and_receive("speed " + std::to_string(speed));
    } else if (speed > 100) {
        std::cerr << "Speed must be less than or equal to than 100cm/s";
    } else {
        std::cerr << "Value error";
    }
}

void Drone::go_xyz_speed(int x, int y, int z, int speed) {
    int abs_x = std::abs(x);
    int abs_y = std::abs(y);
    int abs_z = std::abs(z);

    bool x_is_good = false;
    bool y_is_good = false;
    bool z_is_good = false;
    bool speed_is_good = false;

    if (abs_x < 20) {
        std::cerr << "Distance must be greater than or equal to the "
                     "absolute value of 20cm for x.\n";
    } else if (abs_x <= 500) {
        x_is_good = true;
    } else {
        std::cerr << "Distance must be less than or equal to the "
                     "absolute value of 500cm for x.\n";
    }

    if (abs_y < 20) {
        std::cerr << "Distance must be greater than or equal to the "
                     "absolute value of 20cm for y.\n";
    } else if (abs_y <= 500) {
        y_is_good = true;
    } else {
        std::cerr << "Distance must be less than or equal to the "
                     "absolute value of 500cm for y.\n";
    }

    if (abs_z < 20) {
        std::cerr << "Distance must be greater than or equal to the "
                     "absolute value of 20cm for z.\n";
    } else if (abs_z <= 500) {
        z_is_good = true;
    } else {
        std::cerr << "Distance must be less than or equal to the "
                     "absolute value of 500cm for z.\n";
    }

    if (speed < 10) {
        std::cerr << "Speed must be greater than or equal to 10cm/s.\n";
    } else if (speed <= 100) {
        speed_is_good = true;
    } else {
        std::cerr << "Speed must be less than or equal to 100cm/s.\n";
    }

    if (x_is_good && y_is_good && z_is_good && speed_is_good) {
        send_and_receive("go " + std::to_string(x) + " " + std::to_string(y) +
                         " " + std::to_string(z) + " " + std::to_string(speed));
    } else {
        std::cerr << "Value error\n";
    }
}

void Drone::read_speed() {
    send_and_receive("speed?");
}

void Drone::read_battery() {
    send_and_receive("battery?");
}

void Drone::read_time() {
    send_and_receive("time?");
}

void Drone::read_wifi() {
    send_and_receive("wifi?");
}

void Drone::read_sdk() {
    send_and_receive("sdk?");
}

void Drone::read_sn() {
    send_and_receive("sn?");
}

void Drone::streamon() {
    send_and_receive("streamon");
}
