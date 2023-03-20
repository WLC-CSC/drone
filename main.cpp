#include <iostream>

#include "drone.h"
#include "state.h"
#include "udpsocket.h"

int main() {
    // Drone drone{};
    State state{};
    // drone.takeoff();
    // drone.forward(50);
    // drone.read_battery();
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "State: \n" << state.get_state() << "\n\n";
    }
    // drone.land();
}