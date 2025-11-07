#pragma once
#include <string>

class Player
{
public:
	Player(const std::string& n, int h, int s);
	explicit Player(const std::string& n);
	~Player() = default;
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

