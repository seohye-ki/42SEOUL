#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("scavtrap");
	scav.attack("target");
	scav.takeDamage(30);
	scav.guardGate();
}