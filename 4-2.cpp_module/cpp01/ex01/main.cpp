#include "Zombie.hpp"

// void check_leaks() {
// 	system("leaks zombie");
// }

int main() {
	// atexit(check_leaks);
	Zombie *horde = zombieHorde(15, "hordeZ");
	for(int i = 0; i < 15; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}