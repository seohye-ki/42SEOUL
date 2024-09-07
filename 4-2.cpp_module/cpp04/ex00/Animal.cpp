#include "Animal.hpp"

Animal::Animal() {
	std::cout << "[Animal] Default Constructor called" << std::endl;
	type = "animal";
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

Animal::Animal(const Animal &obj) {
	type = obj.type;
}

Animal& Animal::operator=(const Animal &obj) {
	if (this != &obj) {
		type = obj.type;
	}
	return *this;
}

std::string Animal::getType() const{
	return type;
}

void Animal::makeSound() const{
	std::cout << "..." << std::endl;
}