#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("claptrap");
	clap.attack("target");
	clap.takeDamage(30);

	ScavTrap scav("scavtrap");
	scav.attack("target");
	scav.takeDamage(30);
	scav.guardGate();

	FragTrap frag("fragtrap");
	frag.attack("target");
	frag.takeDamage(50);
	frag.highFivesGuys();
}