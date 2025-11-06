// InheritanceIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <string>
#include <vector>

class Animal {
protected:
    std::string name_;

public:
    Animal(const std::string& name) : name_{ name } {
        std::cout << "Animal-konstruktor\n";
    }

    void speak() const {
        std::cout << name_ << " gör ett ljud.\n";
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {
        std::cout << "Dog-konstruktor\n";
    }

    void wagTail() const {
        std::cout << name_ << " viftar på svansen.\n";
    }
};


template<typename T1, typename T2>
T1 CalcSum(const std::vector<T2>& measurements, const std::string& filterKey) {
    static_assert(std::is_same<T2, Measurement>::value,
        "CalcSum with filter only supports Measurement type");

    T1 sum = T1{ 0 };
    for (const auto& m : measurements) {
        if (m.sensorName == filterKey)
            sum += static_cast<T1>(m.value);
    }
    return sum;
}

int main() {
    Animal animal1("Calle");
    animal1.speak();

    Dog d("Fido");
    Dog d2("Acke");

    d.speak();     // Ärvs från Animal
    d.wagTail();   // Specifikt för Dog
    d2.speak();
    d2.wagTail();

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
