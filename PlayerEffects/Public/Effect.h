#pragma once
#include <iostream>
#include <memory>
#include <vector>

class Effect {
public:
	Effect(const std::string& name);

	virtual ~Effect() = default;
	virtual void apply() = 0;
	virtual void remove() = 0;
	const std::string getName() const;

private:
	std::string name;

protected:
	float effectStrength;
	float modifier;
	float duration;

};

class FreezeEffect : public Effect {
	public:
	FreezeEffect() : Effect("Freeze") {}
	void apply() override {
		std::cout << "Freeze effect!" << std::endl;
	}
	void remove() override {
		std::cout << "Freeze effect gone!" << std::endl;
	}
};

class BurnEffect : public Effect {
	public:
	BurnEffect() : Effect("Burn") {}
	void apply() override {
		std::cout << "Burn effect!" << std::endl;
	}
	void remove() override {
		std::cout << "Burn effect gone!" << std::endl;
	}
};