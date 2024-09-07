#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	name = "default";
	hp = 10;
	energy = 10;
	damage = 0;
}

ClapTrap::ClapTrap(std::string _name){
	std::cout << "Constructor called" << std::endl;
	name = _name;
	hp = 10;
	energy = 10;
	damage = 0;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
	std::cout << "Copy constructor called" << std::endl;
	name = obj.name;
	hp = obj.hp;
	energy = obj.energy;
	damage = obj.damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		name = obj.name;
		hp = obj.hp;
		energy = obj.energy;
		damage = obj.damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (hp > 0 && energy > 0) {
		std::cout << name << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy--;
		std::cout << "==============================================" << std::endl;
		std::cout << name << std::endl;
		std::cout << "HP: " << hp << std::endl;
		std::cout << "ENERGY: " << energy << std::endl;
		std::cout << "DAMAGE: " << damage << std::endl;
		std::cout << "==============================================" << std::endl;
	}
	else
		std::cout << name << " can’t do anything" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hp > 0) {
		std::cout << name << " take damage " << amount << std::endl;
		if (hp < amount)
			hp = 0;
		else
			hp -= amount;
		std::cout << "==============================================" << std::endl;
		std::cout << name << std::endl;
		std::cout << "HP: " << hp << std::endl;
		std::cout << "ENERGY: " << energy << std::endl;
		std::cout << "DAMAGE: " << damage << std::endl;
		std::cout << "==============================================" << std::endl;
	}
	else
		std::cout << name << " already died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy > 0) {
		std::cout << name << " be repaired " << amount << std::endl;
		energy--;
		hp += amount;
		std::cout << "==============================================" << std::endl;
		std::cout << name << std::endl;
		std::cout << "HP: " << hp << std::endl;
		std::cout << "ENERGY: " << energy << std::endl;
		std::cout << "DAMAGE: " << damage << std::endl;
		std::cout << "==============================================" << std::endl;
	}
	else
		std::cout << name << " can’t do anything" << std::endl;
}