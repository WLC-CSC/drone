#include <stdexcept>

#include "drone.h"
#include "state.h"
#include "udpsocket.h"

int main() {
    try {
        Drone drone{};
        drone.takeoff();
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}