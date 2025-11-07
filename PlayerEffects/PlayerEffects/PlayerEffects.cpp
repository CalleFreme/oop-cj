// PlayerEffects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <memory>  // f?r std::unique_ptr och std::make_unique
#include <vector>
#include <iostream>
#include <cstdlib> // f?r rand()
#include <thread>  // f?r sleep_for som l?ter oss pausa exekveringen
#include <chrono>

#include "Effect.h"

// RAII = Resource Acquisition Is Initialization. Inneb?r: Resurser (minne, filer etc) kopplas till ett objekts livstid.
// N?r anv?nda uniqe_ptr?
// Du vill ?ga ett ett dynamiskt allokerat objekt
// Ingen annan ska dela p? det ?garskapet
// du vill att objektet automatiskt frig?rs n?r det g?r ur scope

//Device* d = new Device(); // Dynamisk allokering. Undvik detta om m?jligt!
//d->tick();
//delete d;

// Vi vill anv?nda en "fabrik" f?r att skapa effekter baserat p? en kod (1 = Slow, 2 = Burn)
// Returnerar en unik pekare till en Effect. Anv?nder unique_ptr f?r att hantera minnet automatiskt.
std::unique_ptr<Effect> makeEffect(EffectType type) {
    switch (type) {
    case EffectType::Slow: return std::make_unique<Slow>();
    case EffectType::Burn: return std::make_unique<Burn>();
    default: return nullptr;
    }
}

int main()
{
    // V?rt huvudprogram:
	// Vi b?rjar med att skapa och lagra n?gra effekter i en vektor.
    std::vector<std::unique_ptr<Effect>> effects;
    effects.push_back(makeEffect(EffectType::Slow));
    effects.push_back(makeEffect(EffectType::Burn));

	// Skapa en spelare
	Player player("Mister Hero"); // Vanligt objekt p? stacken. Player-objektet kommer att f?rst?ras automatiskt n?r det g?r ur scope, d.v.s. n?r vi l?mnar main-funktionen.

	// N?r vill vi anv?nda smarta pekare?
	// N?r vi vill lagra flera objekt i en container (vektor, lista etc)
	// auto playerPtr = std::make_unique<Player>("Mister Hero");


	std::cout << player.getName() << " enters the chamber of doom with " << player.getHealth() << " health and speed " << player.getSpeed() << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	// Applicera alla effekter p? spelaren
	for (const auto& effect : effects) {
		effect->apply(player);
	}

	// Genererar random effekter och applicerar dem tills spelaren ?r d?d
    std::cout << "\nApplying random effects until player is defeated:\n";
    while (player.getHealth() > 0) {
        EffectType type = static_cast<EffectType>((rand() % 2) + 1); // Slumpa fram 1 eller 2
        auto effect = makeEffect(type);
        effect->apply(player);
		// V?nta lite mellan effekter
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
	}

	// N?r vi kommer hit, avslutas funktionen och vektorn g?r ur scope och alla unika pekare frig?rs automatiskt.
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
