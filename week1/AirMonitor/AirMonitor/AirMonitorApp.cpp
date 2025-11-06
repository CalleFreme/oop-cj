#include "AirSensor.h"
#include "AirMonitor.h"

int main() {
    std::vector<AirSensor> list = {
        AirSensor("CO2"),
        AirSensor("Humidity"),
        AirSensor("Temperature")
    };

    AirMonitor monitor(list);
    monitor.logAll();

    return 0;
}
