#include <iostream>
#include <string>
int main () {
	std::cout << "Name please: ";
	std::string name;
	std::cin >> name;
	std::cout << "You're cute, " << name << std::endl;
	return 0;
}