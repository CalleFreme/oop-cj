#pragma once
#include <string>

class Device {
private:
    int id;
    std::string name;

public:
    Device(int id, const std::string& name);
    void rename(const std::string& newName);
    void printInfo() const;
};
