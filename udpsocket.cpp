#include "udpsocket.h"

#include <atomic>
#include <cstring>
#include <stdexcept>

constexpr std::size_t buffer_size = 1518;

UDPSocket::UDPSocket(const std::string& ip_address, int port)
    : ip_address{ip_address}, port{port}, recv_buffer(buffer_size) {
#ifdef _WIN32
    WSADATA wsa;
    WORD version = MAKEWORD(2, 2);
    int wsOk = WSAStartup(version, &wsa);
    if (wsOk != 0) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ") "};
        throw std::runtime_error(error_message + std::strerror(wsOk));
    }

    socket_handle = socket(AF_INET, SOCK_DGRAM, 0);

    if (socket_handle == INVALID_SOCKET) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ") "};
        throw std::runtime_error(error_message +
                                 std::strerror(WSAGetLastError()));
    }
#else
    socket_handle =
        socket(AF_INET, SOCK_DGRAM, 0);  // This may cause errors on Linux/Mac
    if (socket_handle == -1) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ") "};
        throw std::runtime_error(error_message + std::strerror(errno));
    }
#endif

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

#ifdef _WIN32
    if (bind(socket_handle, (struct sockaddr*)&address, sizeof(address)) ==
        SOCKET_ERROR) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ") "};
        throw std::runtime_error(error_message +
                                 std::strerror(WSAGetLastError()));
    }
#else
    if (bind(socket_handle, (struct sockaddr*)&address, sizeof(address)) ==
        -1) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ") "};
        throw std::runtime_error(error_message + std::strerror(errno));
    }
#endif
}

UDPSocket::~UDPSocket() {
    closesocket(socket_handle);
#ifdef _WIN32
    WSACleanup();
#endif
}

void UDPSocket::send(const std::string& message) {
    // construct destination address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip_address.data());
    address.sin_port = htons(port);

#ifdef _WIN32
    int send_length = sendto(socket_handle, message.data(), message.size(), 0,
                             (struct sockaddr*)&address, sizeof(address));

    if (send_length == -1) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ")::send(\""};
        error_message += message + "\") ";
        throw std::runtime_error(error_message +
                                 std::strerror(WSAGetLastError()));
    }
#else
    ssize_t send_length =
        sendto(socket_handle, message.data(), message.size(), 0,
               (struct sockaddr*)&address, sizeof(address));

    if (send_length == -1) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ")::send(\""};
        error_message += message + "\") ";
        throw std::runtime_error(error_message + std::strerror(errno));
    }
#endif
}

std::string UDPSocket::recv() {
#ifdef _WIN32
    int recv_length = recvfrom(socket_handle, recv_buffer.data(),
                               recv_buffer.size(), 0, nullptr, nullptr);
    if (recv_length == SOCKET_ERROR) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ")::recv()"};
        throw std::runtime_error(error_message +
                                 std::strerror(WSAGetLastError()));
    }
#else
    ssize_t recv_length = recvfrom(socket_handle, recv_buffer.data(),
                                   recv_buffer.size(), 0, nullptr, nullptr);
    if (recv_length == -1) {
        std::string error_message{"UDPSocket(" + ip_address + ", " +
                                  std::to_string(port) + ")::recv()"};
        throw std::runtime_error(error_message + std::strerror(errno));
    }
#endif

    std::string message{std::begin(recv_buffer),
                        std::begin(recv_buffer) + recv_length};
    return message;
}