#include "ClapTrap.hpp"

int main() {
	ClapTrap a("clap_a");
	ClapTrap b("clap_b");

	/*hp 소모*/
	a.attack("target");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(100);

	/*energy 소모*/
	b.attack("target1");
	b.attack("target2");
	b.attack("target3");
	b.attack("target4");
	b.attack("target5");
	b.attack("target6");
	b.attack("target7");
	b.attack("target8");
	b.attack("target9");
	b.attack("target10");
	b.attack("target11");
	b.beRepaired(20);

	return 0;
}