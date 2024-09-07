#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
	std::cout << "my name is " << _name << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " is dead." << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}