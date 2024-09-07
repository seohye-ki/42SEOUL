#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "[WrongAnimal] Default Constructor called" << std::endl;
	type = "wrong animal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj) {
	if (this != &obj) {
		type = obj.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const{
	return type;
}

void WrongAnimal::makeSound() const{
	std::cout  << " " << std::endl;
}
