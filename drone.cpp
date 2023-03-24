#include "drone.h"

#include <iostream>

Drone::Drone(std::string ip, int port) : socket{ip, port} {
    socket.send("command");
    std::cout << socket.recv() << '\n';
}

Drone::~Drone() {
    send_and_receive("land");
}

void Drone::send_and_receive(std::string command) {
    socket.send(command);
    std::cout << socket.recv() << '\n';
}

void Drone::handle_default_bounds(int value, int lower_bound, int upper_bound) {
    if (value < lower_bound) {
        throw std::runtime_error("Value cannot be lower than " +
                                 std::to_string(lower_bound));
    }
    if (value > upper_bound) {
        throw std::runtime_error("Value cannot be higher than " +
                                 std::to_string(upper_bound));
    }
}

void Drone::takeoff() {
    send_and_receive("takeoff");
}

void Drone::land() {
    send_and_receive("land");
}

void Drone::flip(char direction) {
    if (direction == 'l' || direction == 'r' || direction == 'f' ||
        direction == 'b') {
        send_and_receive("flip " + std::string(1, direction));  // l, r, f, b
    } else {
        throw std::runtime_error("Direction must be either 'l', 'r', 'f', 'b'");
    }
}

void Drone::emergency() {
    send_and_receive("emergency");
}

void Drone::stop() {
    send_and_receive("stop");
}

void Drone::up(int distance) {
    handle_default_bounds(distance, 20, 500);
    send_and_receive("up " + std::to_string(distance));
}

void Drone::down(int distance) {
    handle_default_bounds(distance, 20, 500);
    send_and_receive("down " + std::to_string(distance));
}

void Drone::left(int distance) {
    handle_default_bounds(distance, 20, 500);
    send_and_receive("left " + std::to_string(distance));
}

void Drone::right(int distance) {
    handle_default_bounds(distance, 20, 500);
    send_and_receive("right " + std::to_string(distance));
}

void Drone::forward(int distance) {
    handle_default_bounds(distance, 20, 500);
    send_and_receive("forward " + std::to_string(distance));
}

void Drone::backward(int distance) {
    handle_default_bounds(distance, 20, 500);
    send_and_receive("backward " + std::to_string(distance));
}

void Drone::clockwise(int degrees) {
    handle_default_bounds(degrees, 1, 360);
    send_and_receive("cw " + std::to_string(degrees));
}

void Drone::counter_clockwise(int degrees) {
    handle_default_bounds(degrees, 1, 360);
    send_and_receive("ccw " + std::to_string(degrees));
}

void Drone::change_speed(int speed) {
    handle_default_bounds(speed, 10, 100);
    send_and_receive("speed " + std::to_string(speed));
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

void Drone::streamoff() {
    send_and_receive("streamoff");
}

void Drone::streamon() {
    send_and_receive("streamon");
}

void Drone::read_temp() {
    send_and_receive("temp?");
}

void Drone::read_height() {
    send_and_receive("height?");
}

void Drone::read_attitude() {
    send_and_receive("attitude?");
}

void Drone::read_tof() {
    send_and_receive("tof?");
}

void Drone::read_acceleration() {
    send_and_receive("acceleration?");
}

void Drone::read_baro() {
    send_and_receive("baro?");
}