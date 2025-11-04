#pragma once
#include <string>
#include "SensorReading.h"

class Sensor {
private:
    std::string name;

public:
    Sensor(const std::string& name);
    SensorReading read() const;
    std::string getName() const;
};
