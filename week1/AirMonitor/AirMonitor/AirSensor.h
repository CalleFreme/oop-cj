#pragma once
#include <string>
#include "SensorReading.h"

class AirSensor {
private:
    std::string name;

public:
    AirSensor(const std::string& name);
    SensorReading read() const;
    std::string getName() const;
};
