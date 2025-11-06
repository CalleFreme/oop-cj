// PolymorphismIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>

//struct Base { 
//    virtual ~Base() = default;
//    virtual void f() const { std::cout << "Base\n"; }
//};
//
//struct Derived : Base { 
//    void f() const override { std::cout << "Der\n"; }
//};

int main()
{

    std::vector<std::unique_ptr<Effect>> effects;
    effects.push_back(makeEffect(1));
    effects.push_back(makeEffect(2));
    for (auto& e : effects) if (e) e->apply();

    //Derived d;
    //Base b = d; // Slicing: b är en Base, inte Der
    //b.f(); // Skriver "Base"
    
    //Derived derivedObj;
    //Base& ref = derivedObj; // referens till basklassen
    //Base* ptr = &derivedObj; // pekare till basklassen

    //ref.f();
    //ptr->f();

    // När du har en en klass med minst EN virtuell funktion,
    // lägger kompilatorn till en s.k. vtable-pekare (vptr) i objektet.
    // Den pekar till en tabell med pekare till klassens virtuella funktioner.
    // Virtual dispatch fungerar endast via pekare eller referenser till bas.
}

