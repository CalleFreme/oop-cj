#pragma once
#include <vector>
#include "AirSensor.h"
#include "Logger.h"

class AirMonitor {
private:
    std::vector<AirSensor> sensors;

public:
    AirMonitor(const std::vector<AirSensor>& sensors);
    void addSensor(const AirSensor& s);
    void logAll() const;
};
