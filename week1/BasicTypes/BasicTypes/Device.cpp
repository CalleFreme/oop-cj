#include "Device.h"
#include <iostream>

Device::Device(int id, const std::string& name)
    : id(id), name(name) {
}

void Device::rename(const std::string& newName) {
    name = newName;
}

void Device::printInfo() const {
    std::cout << "Device(id=" << id << ", name=" << name << ")" << std::endl;
}
