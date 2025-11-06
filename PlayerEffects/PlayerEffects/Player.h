#pragma once
#include <string>

class Player
{
public:
	Player(const std::string& n, int h, int s); // Konstruktor
	Player(const std::string& n); // Överlagrad konstruktor, när vi bara vill ange namn för ny spelare
	~Player() = default; // Standarddestruktor. Behövs bara om vi använder råa pekare i klassen, d.v.s. allokerar minne dynamiskt.

	const std::string& getName() const;
	int getHealth() const;
	int getSpeed() const;

	void takeDamage(int dmg);
	void changeSpeed(int delta);
private:
	std::string name;
	int health;
	int speed;
};

