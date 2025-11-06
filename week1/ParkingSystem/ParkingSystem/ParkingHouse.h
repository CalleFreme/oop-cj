#pragma once
#include <vector>
#include "Car.h"

class ParkingHouse {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car);
    bool removeCar(const std::string& regNumber);
    void printStatus();
};
