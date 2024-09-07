#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
			std::string	name;
	public:
			DiamondTrap();
			DiamondTrap(std::string _name);
			~DiamondTrap();
			DiamondTrap(const DiamondTrap &obj);
			DiamondTrap& operator=(const DiamondTrap &obj);
			void	attack(const std::string& target);
			void	whoAmI();
};

#endif