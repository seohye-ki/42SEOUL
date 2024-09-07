#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *meta[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete meta[i];
	
	Cat cat;
	Cat &cat_ref = cat;
	cat.getBrain()->setIdea(1, "good idea");
	std::cout << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << cat.getBrain()->getIdea(1) << std::endl;
	
	Cat cat_copy(cat_ref);
	std::cout << cat_copy.getBrain()->getIdea(0) << std::endl;
	std::cout << cat_copy.getBrain()->getIdea(1) << std::endl;

	return 0;
}