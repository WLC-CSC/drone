#include <iostream>
#include <stdexcept>

#include "coordinate.h"
#include "drone.h"
#include "navigations.h"
#include "state.h"
#include "statedata.h"
#include "udpsocket.h"

int main() {
    try {
        Drone drone{};
        // State state;
        // drone.takeoff();

        // while (true) {
        //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //     StateData statedata = state.get_state();
        //     std::cout << statedata.get_state() << "\n";
        // }

        fly_manhatten_xyz(drone, 600, 500, 70);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}