#include "Player.h"
#include <iostream>
Player::Player(const std::string& n, int h, int s) : name(n), health(h), speed(s) {}
Player::Player(const std::string& n) : name(n), health(100), speed(10) {}

const std::string& Player::getName() const { return name; }
int Player::getHealth() const { return health; }
int Player::getSpeed() const { return speed; }

void Player::takeDamage(int dmg) {
	float dodgeChance = speed * 0.1f;

	if (dodgeChance < 0.0f) dodgeChance = 0.0f;
	if (dodgeChance > 0.9f) dodgeChance = 0.9f; 
	float roll = static_cast<float>(rand()) / RAND_MAX;

	if (roll < dodgeChance) {
		std::cout << name << " dodges the attack!\n";
		return;
	}

    health -= dmg;
	std::cout << "Ouch! " << name << " takes " << dmg << " damage. Health is now " << health << ".\n";
    if (health < 0) {
        health = 0;
		std::cout << name << " has been defeated!\n";
    }
}

void Player::changeSpeed(int delta) {
    speed += delta;
	std::cout << "Yaaawn! " << name << "'s speed changes by " << delta << ". Speed is now " << speed << ".\n";
    if (speed < 0) {
        speed = 0;
		std::cout << name << ": I can't move!\n";
    }
}
