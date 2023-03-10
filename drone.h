#pragma once
#include "udpsocket.h"

class Drone {
public:
    Drone();
    void send_and_receive(std::string command);
    void handle_int_values(std::string command, int lower_bound,
                           int upper_bound, int value);
    void handle_upper_bound(int value, int lower_bound, int upper_bound,
                            int iterations);

    // Control Commands
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
    // void xyz(int x, int y, int z);
    // void manhattan_xyz(int x, int y, int z);
    void go_xyz_speed(int x, int y, int z, int speed);
    void curve_xyz_speed(int x1, int y1, int z1, int x2, int y2, int z2,
                         int speed);
    void change_speed(int speed);

    // Read Commands
    void read_speed();
    void read_battery();
    void read_time();
    void read_wifi();
    void read_sdk();
    void read_sn();

    // Video Stream
    void streamon();
    void streamoff();

private:
    const std::string ip = "192.168.10.1";
    const int port = 8889;
    UDPSocket socket;
    std::string command;
    int value;
    int distance;
    int degrees;
    int speed;
    int x;
    int y;
    int z;
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
};