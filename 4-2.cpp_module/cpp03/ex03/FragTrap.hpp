#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
			FragTrap();
			FragTrap(std::string _name);
			~FragTrap();
			FragTrap(const FragTrap &obj);
			FragTrap& operator=(const FragTrap &obj);
			void	highFivesGuys(void);
};

#endif