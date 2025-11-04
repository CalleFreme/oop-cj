#include "Sensor.h"
#include <iostream>

Sensor::Sensor(const std::string& name)
    : name(name) {
}

SensorReading Sensor::read() const {
    SensorReading r;
    r.value = 42.0; // dummyvärde
    r.timestamp = "2025-10-28 14:35";
    return r;
}

std::string Sensor::getName() const {
    return name;
}
