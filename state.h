#pragma once
#include <atomic>
#include <mutex>
#include <thread>

#include "udpsocket.h"

class State {
public:
    State(std::string ip = "0.0.0.0", int port = 8890);
    ~State();
    std::string get_state();

private:
    UDPSocket socket;
    std::string state_info;

    std::mutex m;
    std::atomic<bool> running;
    std::thread thread;

    void recv();
};