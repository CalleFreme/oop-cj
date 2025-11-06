#include "Car.h"
#include <iostream>

void Car::print() const {
    std::cout << "Car(reg=" << regNumber
        << ", arrival=" << arrivalTime << ")" << std::endl;
}
