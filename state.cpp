#include "state.h"

#include <chrono>
#include <thread>

State::State(std::string ip, int port) : socket{ip, port}, running{false}, thread{&State::recv, this} {
    UDPSocket s{"192.168.10.1", 8889};
    s.send("command");
    s.recv();
    s.send("moff");
    s.recv();
    running.store(true);
};

State::~State() {
    running.store(false);
    thread.join();
}

std::string State::get_state() {
    std::lock_guard<std::mutex> lock(m);
    return state_info;
}

void State::recv() {
    while (!running.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    while (running.load()) {
        std::string info = socket.recv();
        if (info.length() > 0) {
            std::lock_guard<std::mutex> lock(m);
            state_info = info;
        }
    }
}