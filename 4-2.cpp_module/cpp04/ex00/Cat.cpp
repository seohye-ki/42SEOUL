#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Hi Cat!" << std::endl;
	type = "cat";
}

Cat::~Cat() {
	std::cout << "Goodbye Cat!" << std::endl;
}

Cat::Cat(const Cat &obj) {
	type = obj.type;
}

Cat& Cat::operator=(const Cat &obj) {
	if (this != &obj) {
		type = obj.type;
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "meawoo~" << std::endl;
}