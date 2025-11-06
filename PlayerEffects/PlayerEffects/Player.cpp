#include "Player.h"
#include <iostream>

// Fullständig konstruktor: initierar alla medlemmar.
Player::Player(const std::string& n, int h, int s) : name(n), health(h), speed(s) {}
// Överlagrad konstruktor: initierar namn, sätter standardvärden för hälsa och hastighet.
Player::Player(const std::string& n) : name(n), health(100), speed(10) {}

const std::string& Player::getName() const { return name; }
int Player::getHealth() const { return health; }
int Player::getSpeed() const { return speed; }

void Player::takeDamage(int dmg) {
	// Spelaren har en chans att undvika skadan helt, baserat på sin hastighet.
	float dodgeChance = speed * 0.1f; // 10% chans att undvika skada per hastighetsenhet

	if (dodgeChance < 0.0f) dodgeChance = 0.0f;
	if (dodgeChance > 0.9f) dodgeChance = 0.9f; // Max 90% chans att undvika

	// rand() genererar ett heltal mellan 0 och RAND_MAX=32767
	// static_cast för att konvertera till float för att få ett decimaltal
	// Dividera med RAND_MAX för att få ett tal mellan 0.0 och 1.0 (d.v.s. 0% till 100%)
	float roll = static_cast<float>(rand()) / RAND_MAX; // Slumpa fram ett tal mellan 0.0 och 1.0

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
