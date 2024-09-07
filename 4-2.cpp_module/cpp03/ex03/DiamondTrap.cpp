#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "[diatrap] default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) {
	std::cout << "[diatrap] constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[diatrap] Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
	/* data */
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this != &obj) {
	/* data */
	}
	return *this;
}

void DiamondTrap::whoAmI() {

}
