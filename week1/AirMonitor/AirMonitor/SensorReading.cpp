#include "SensorReading.h"
#include <iostream>

void SensorReading::print() const {
    std::cout << "SensorReading(value=" << value
        << ", timestamp=" << timestamp << ")";
}
