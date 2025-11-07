#pragma once
#include <iostream>
#include <memory>
#include "Player.h"

struct ;

enum class EffectType {
    Slow = 1,
    Burn = 2
};

struct Effect {
	virtual ~Effect() = default;
	virtual void apply(Player& player) = 0;
    static std::unique_ptr<Effect> makeEffect(EffectType type);
};

struct Slow : Effect {
    void apply(Player& player) override {
        std::cout << "Slowing " << player.getName() << "...\n";
		player.changeSpeed(-1);
    }
};

struct Burn : Effect {
    void apply(Player& player) override {
        std::cout << "Burning " << player.getName() << "!\n";
        player.takeDamage(5);
    }
};

