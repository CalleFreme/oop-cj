#include "AirMonitor.h"

AirMonitor::AirMonitor(const std::vector<AirSensor>& sensors)
    : sensors(sensors) {
}

void AirMonitor::addSensor(const AirSensor& s) {
    sensors.push_back(s);
}

void AirMonitor::logAll() const {
    Logger logger;
    for (const auto& s : sensors) {
        SensorReading r = s.read();
        logger.log(r, s.getName());
    }
}
