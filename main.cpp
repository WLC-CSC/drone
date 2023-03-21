#include <iostream>
#include <stdexcept>

#include "drone.h"
#include "navigations.h"
#include "state.h"
#include "udpsocket.h"

int main() {
    try {
        Drone drone{};
        Navigations navigations{drone};
        drone.takeoff();
        navigations.go_xyz(30, -40, 30);

    } catch (std::exception& e) {
        std::cout << e.what();
    }
}