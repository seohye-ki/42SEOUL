#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
			std::string	type;
	public:
			WrongAnimal();
			virtual ~WrongAnimal();
			WrongAnimal(const WrongAnimal& obj);
			WrongAnimal& operator=(const WrongAnimal& obj);
			std::string		getType() const;
			virtual void	makeSound() const;
};

#endif
