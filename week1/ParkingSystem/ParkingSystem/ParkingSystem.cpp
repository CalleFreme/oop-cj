#include "ParkingHouse.h"
#include <iostream>

int main() {
    ParkingHouse ph;

    Car c1{ "ABC123", "2025-10-28 09:00" };
    Car c2{ "XYZ789", "2025-10-28 09:30" };
    Car c3{ "MNO456", "2025-10-28 10:00" };

    ph.addCar(c1);
    ph.addCar(c2);
    ph.addCar(c3);

    // Kan även skapa vektor av bilar såhär:
    //std::vector<Car> cars{
    //{ "ABC-123", "08:00" },
    //{ "XYZ-999", "08:15" },
    //{ "JKL-456", "08:30" }
    //};

    ph.printStatus();

    std::cout << "Removing car XYZ789...\n";
    ph.removeCar("XYZ789");

    ph.printStatus();

    return 0;
}
