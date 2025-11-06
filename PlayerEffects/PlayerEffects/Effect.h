#pragma once
#include <iostream>
#include "Player.h"

struct Effect {
	virtual ~Effect() = default; // Måste ha virtuell destruktor i bas-klasser.
	virtual void apply(Player& player) = 0;	// Ren virtuell funktion. "= 0" betyder att den måste implementeras i subklasser.
};

struct Slow : Effect {
    void apply(Player& player) override {
        std::cout << "Slowing " << player.getName() << "...\n";
		player.changeSpeed(-1); // Sänk spelarens hastighet med 10%
    }
};

struct Burn : Effect {
    void apply(Player& player) override {
        std::cout << "Burning " << player.getName() << "!\n";
        player.takeDamage(5); // Gör 5 skada
    }
};

