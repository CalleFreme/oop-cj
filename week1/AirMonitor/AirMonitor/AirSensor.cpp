#include "AirSensor.h"

AirSensor::AirSensor(const std::string& name)
    : name(name) {
}

SensorReading AirSensor::read() const {
    SensorReading r;
    r.value = 50.0; // exempelvärde
    r.timestamp = "2025-10-28 15:00";
    return r;
}

std::string AirSensor::getName() const {
    return name;
}
