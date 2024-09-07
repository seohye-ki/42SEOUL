#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
			std::string		name;
			unsigned int	hp;
			unsigned int	energy;
			unsigned int	damage;
	public:
			ClapTrap();
			ClapTrap(std::string _name);
			~ClapTrap();
			ClapTrap(const ClapTrap &obj);
			ClapTrap& operator=(const ClapTrap &obj);
			virtual void	attack(const std::string& target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
};

#endif