#pragma once
#include <iostream>

struct Position {
    double x;
    double y;

    void move(double dx, double dy);   // Flytta punkten
    void print() const;                // Skriv ut positionen
};
