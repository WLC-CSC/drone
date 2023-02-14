#pragma once

#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include <string>
#include <vector>

class UDPSocket {
public:
    UDPSocket(const std::string& ip_address, int port);
    ~UDPSocket();

    void send(const std::string& message);
    std::string recv();

private:
    std::string ip_address;  // ip addrs
    int port;
#ifdef _WIN32
    SOCKET socket_handle;
    std::vector<char> recv_buffer;
#else
    int socket_handle;
    std::vector<unsigned char> recv_buffer;
#endif
};