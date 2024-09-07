#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}