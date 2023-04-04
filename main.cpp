#include <iostream>
#include <stdexcept>

#include "drone.h"
#include "navigations.h"
#include "state.h"
#include "statedata.h"
#include "udpsocket.h"

int main() {
    try {
        Drone drone{};
        State state;
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            StateData statedata = state.get_state();
            std::cout << statedata.get_state() << "\n";
        }

    } catch (std::exception& e) {
        std::cout << e.what();
    }
}