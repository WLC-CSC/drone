#pragma once
#include "udpsocket.h"

class Drone {
public:
    Drone(std::string ip = "192.168.10.1", int port = 8889);
    ~Drone();
    void send_and_receive(std::string command);
    void handle_default_bounds(int value, int lower_bound, int upper_bound);

    // Default Drone Commands
    void takeoff();
    void land();
    void flip(char direction);
    void emergency();
    void stop();
    void up(int distance);
    void down(int distance);
    void left(int distance);
    void right(int distance);
    void forward(int distance);
    void backward(int distance);
    void clockwise(int degrees);
    void counter_clockwise(int degrees);
    void change_speed(int speed);

    // Read Commands
    void read_speed();
    void read_battery();
    void read_time();
    void read_wifi();
    void read_sdk();
    void read_sn();

    void read_temp();
    void read_height();
    void read_attitude();
    void read_tof();
    void read_acceleration();
    void read_baro();

    // Video Stream
    void streamon();
    void streamoff();

private:
    UDPSocket socket;
};