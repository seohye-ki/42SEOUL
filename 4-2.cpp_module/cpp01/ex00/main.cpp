#include "Zombie.hpp"

// void check_leaks() {
// 	system("leaks zombie");
// }

int main() {
	// atexit(check_leaks);
	Zombie stack("stack zombie");
	Zombie *heap = newZombie("heap zombie");

	randomChump("random chump zombie");
	stack.announce();
	heap->announce();
	delete heap;
	return (0);
}