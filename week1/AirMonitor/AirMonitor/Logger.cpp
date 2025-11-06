#include "Logger.h"
#include <iostream>

void Logger::log(const SensorReading& reading, const std::string& sensorName) const {
    std::cout << "Logging from sensor '" << sensorName << "': ";
    reading.print();
    std::cout << std::endl;
}
