#include "commands.h"

#include <cmath>
#include <stdexcept>

std::string Commands::command() {
    return "command";
}
std::string Commands::takeoff() {
    return "takeoff";
}
std::string Commands::land() {
    return "land";
}
std::string Commands::emergency() {
    return "emergency";
}
std::string Commands::stop() {
    return "stop";
}
std::string Commands::up(int distance) {
    if (distance < 20) {
        throw "Distance must be more than 20 cm.\n";
    } else if (distance < 500) {
        std::string output = "up " + std::to_string(distance);
        return output;
    }
    return "";
}
std::string Commands::down(int distance) {
    if (distance < 20) {
        throw "Distance must be more than 20 cm.\n";
    } else if (distance < 500) {
        std::string output = "down " + std::to_string(distance);
        return output;
    }
    return "";
}
std::string Commands::left(int distance) {
    if (distance < 20) {
        throw "Distance must be more than 20 cm.\n";
    } else if (distance < 500) {
        std::string output = "left " + std::to_string(distance);
        return output;
    }
    return "";
}
std::string Commands::right(int distance) {
    if (distance < 20) {
        throw "Distance must be more than 20 cm.\n";
    } else if (distance < 500) {
        std::string output = "right " + std::to_string(distance);
        return output;
    }
    return "";
}
std::string Commands::forward(int distance) {
    if (distance < 20) {
        throw "Distance must be more than 20 cm.\n";
    } else if (distance < 500) {
        std::string output = "forward " + std::to_string(distance);
        return output;
    }
    return "";
}
std::string Commands::backward(int distance) {
    if (distance < 20) {
        throw "Distance must be more than 20 cm.\n";
    } else if (distance < 500) {
        std::string output = "backward " + std::to_string(distance);
        return output;
    }
    return "";
}
std::string Commands::clockwise(int degrees) {
    if (degrees > 360) {
        throw "Degrees must be less than 360 degrees.\n";
    } else if (degrees < 1) {
        throw "Degrees must be at least 1 degree.\n";
    } else {
        std::string output = "cw " + std::to_string(degrees);
        return output;
    }
    return "";
}
std::string Commands::counter_clockwise(int degrees) {
    if (degrees > 360) {
        throw "Degrees must be less than 360 degrees.\n";
    } else if (degrees < 1) {
        throw "Degrees must be at least 1 degree.\n";
    } else {
        std::string output = "ccw " + std::to_string(degrees);
        return output;
    }
}

// std::string Commands::xyz(int x, int y, int z) {
//     double pi = 2 * acos(0.0);
//     double horizontal_distance = sqrt((x ^ 2) + (y ^ 2));
//     double yaw = atan2(y, x) * 180 / pi;
//     double vertical_distance = z;
// }

std::string Commands::manhattan_xyz(int x, int y, int z) {
    std::string command;
    if (z >= 20) {
        command = "up " + std::to_string(z) + "\n";
    } else if (z <= -20) {
        z = z * -1;
        command = "down " + std::to_string(z) + "\n";
    } else {
        throw "Z cannot be in the range between -20 and 20\n";
    }

    if (x >= 20) {
        command = "right " + std::to_string(x) + "\n";
    } else if (x <= -20) {
        x = x * -1;
        command = "left " + std::to_string(x) + "\n";
    } else {
        throw "X cannot be in the range between -20 and 20\n";
    }

    if (y >= 20) {
        command = "forward " + std::to_string(y) + "\n";
    } else if (y <= -20) {
        y = y * -1;
        command = "backward " + std::to_string(y) + "\n";
    } else {
        throw "Y cannot be in the range between -20 and 20\n";
    }

    return command;
}

std::string Commands::speed(int speed) {
    if (speed < 10) {
        throw "Speed must be between 10 and 100\n";
    } else if (speed > 500) {
        throw "Speed must be between 10 and 100\n";
    } else {
        return "speed " + std::to_string(speed) + "\n";
    }
}