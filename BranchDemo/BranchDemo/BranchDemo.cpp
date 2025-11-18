#include <iostream>

int add(int a, int b) {
	std::cout << "[LOG] add function called with arguments: " << a << ", " << b << "\n";
    return a + b;  // Basfunktion att ändra i demonstration
}

int main() {
	std::cout << "[LOG] starting program\n";
    std::cout << "Add 2 + 3 = " << add(2, 3) << "\n";
    return 0;
}
