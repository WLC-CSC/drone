#pragma once
#include "udpsocket.h"

class Drone {
public:
    Drone();
    const std::string ip = "192.168.10.1";
    const int port = 8889;
    UDPSocket socket{ip, port};

private:
};