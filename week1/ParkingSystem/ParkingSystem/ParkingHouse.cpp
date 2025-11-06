#include "ParkingHouse.h"
#include <iostream>
#include <algorithm>
#include <string>

void printHeader(const char* title) {
    std::cout << "\n--- " << title << " ---\n";
}

void ParkingHouse::addCar(const Car& car) {
    cars.push_back(car);
}

bool ParkingHouse::removeCar(const std::string& regNumber) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->regNumber == regNumber) {
            cars.erase(it);
            return true;
        }
    }
    return false;
}

void ParkingHouse::printStatus() {
    std::cout << "--- Parking status ---" << std::endl;
    for (const auto& car : cars) {
        car.print();
    }

    // 1) Index-based loop (classic)
    printHeader("Index-based loop");
    for (size_t i = 0; i < cars.size(); ++i) {
        // cars[i] returns a Car& so we access members with dot
        std::cout << "cars[" << i << "] ";
        cars[i].print();
    }

    // 2) Iterator-based loop (pointer-like)
    printHeader("Iterator-based loop (use -> or * )");
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        // 'it' is an iterator (acts like a pointer). Use -> to access members:
        std::cout << "using it-> : ";
        it->print();

        // Equivalent explicit dereference:
        std::cout << "using (*it). : ";
        (*it).print();
    }

    // 3) Range-based for (recommended for simple read-only or ref access)
    printHeader("Range-based for loop");
    for (const auto& car : cars) {
        car.print();
    }

    // 4) Using std::find_if to find and erase by registration number
    printHeader("Find and erase (std::find_if + erase)");
    const std::string toRemove = "XYZ-999";
    auto it = std::find_if(cars.begin(), cars.end(),
        [&](const Car& c) { return c.regNumber == toRemove; });
    if (it != cars.end()) {
        std::cout << "Found " << toRemove << ", erasing...\n";
        // erase expects an iterator, so we pass 'it' directly
        cars.erase(it);
    }
    else {
        std::cout << toRemove << " not found\n";
    }

    printHeader("After erase");
    for (const auto& car : cars) car.print();

    // 5) Reverse iterator example
    printHeader("Reverse iteration (rbegin/rend)");
    for (auto rit = cars.rbegin(); rit != cars.rend(); ++rit) {
        // rit-> is fine too (reverse_iterator also yields elements)
        rit->print();
    }
}



