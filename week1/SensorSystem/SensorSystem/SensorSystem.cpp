#include "Sensor.h"
#include "Logger.h"

void foo() {
    // "foo" är ett vanligt s.k. "dummy name" för funktioner som vi inte har ett bra namn på ännu
    // Vad skulle foo kunna heta istället, som är mer beskrivande för vad som händer i funktionen?
    Sensor tempSensor("TemperatureSensor");
    Logger logger;
    SensorReading tempReading = tempSensor.read();
    logger.log(tempReading, tempSensor.getName());
}

int main() {
    foo();
    return 0;
}
