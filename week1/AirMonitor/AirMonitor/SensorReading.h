#pragma once
#include <string>

struct SensorReading {
    double value;
    std::string timestamp;

    void print() const;
};
