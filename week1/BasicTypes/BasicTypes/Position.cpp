#include "Position.h"

void Position::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Position::print() const {
    std::cout << "Position(x=" << x << ", y=" << y << ")" << std::endl;
}
