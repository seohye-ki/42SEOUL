#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Hi Dog!" << std::endl;
	type = "dog";
}

Dog::~Dog() {
	std::cout << "Goodbye Dog!" << std::endl;
}

Dog::Dog(const Dog &obj) {
	type = obj.type;
}

Dog& Dog::operator=(const Dog &obj) {
	if (this != &obj) {
		type = obj.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "bark!" << std::endl;
}
