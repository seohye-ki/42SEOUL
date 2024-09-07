#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << "==========================================================" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << "==========================================================" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound(); //will output the cat sound!
	wrong->makeSound();
	std::cout << "==========================================================" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete wrong;

	return 0;
}