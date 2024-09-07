#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "Hi wrongCat!" << std::endl;
	type = "wrongcat";
}

WrongCat::~WrongCat() {
	std::cout << "Goodbye WrongCat!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) {
	type = obj.type;
}

WrongCat& WrongCat::operator=(const WrongCat &obj) {
	if (this != &obj) {
		type = obj.type;
	}
	return *this;
}
