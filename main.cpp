#include "drone.h"
#include "udpsocket.h"

int main() {
    Drone drone{};
    drone.takeoff();
    drone.flip('l');
    drone.land();
}