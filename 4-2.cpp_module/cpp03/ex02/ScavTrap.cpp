#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap() {
	std::cout << "[scavtrap] Default constructor called" << std::endl;
	name = "default scav";
	hp = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(std::string _name):ClapTrap(_name){
	std::cout << "[scavtrap] Constructor called" << std::endl;
	name = _name;
	hp = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "[scavtrap] Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) {
	std::cout << "[scavtrap] Copy constructor called" << std::endl;
	name = obj.name;
	hp = obj.hp;
	energy = obj.energy;
	damage = obj.damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	std::cout << "[scavtrap] Copy assignment operator called" << std::endl;
	if (this != &obj) {
		name = obj.name;
		hp = obj.hp;
		energy = obj.energy;
		damage = obj.damage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (hp > 0 && energy > 0) {
		std::cout << "[scavtrap] " << name << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy--;
		std::cout << "==============================================" << std::endl;
		std::cout << name << std::endl;
		std::cout << "HP: " << hp << std::endl;
		std::cout << "ENERGY: " << energy << std::endl;
		std::cout << "DAMAGE: " << damage << std::endl;
		std::cout << "==============================================" << std::endl;
	}
	else
		std::cout << "[scavtrap] " << name << " can’t do anything" << std::endl;
}

void ScavTrap::guardGate() {
	if (hp > 0 && energy > 0) {
		std::cout << "[scavtrap] " << name << " Gate keeper mode." << std::endl;
		energy--;
	}
	else
		std::cout << "[scavtrap] " << name << " can’t do anything" << std::endl;
}