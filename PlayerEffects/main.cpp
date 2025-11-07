#include "main.h"
#include <iostream>
#include <thread>
#include <vector>
#include "Player.h"
#include "Effect.h"

int main()
{
    std::vector<std::unique_ptr<Effect>> effects;
    effects.push_back(Effect::makeEffect(EffectType::Slow));
    effects.push_back(Effect::makeEffect(EffectType::Burn));
	Player player("Mister Hero");
	std::cout << player.getName() << " enters the chamber of doom with " << player.getHealth() << " health and speed " << player.getSpeed() << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	for (const auto& effect : effects) {
		effect->apply(player);
	}
    std::cout << "\nApplying random effects until player is defeated:\n";
    while (player.getHealth() > 0) {
        EffectType type = static_cast<EffectType>((rand() % 2) + 1);
        auto effect = Effect::makeEffect(type);
        effect->apply(player);
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
	}
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file