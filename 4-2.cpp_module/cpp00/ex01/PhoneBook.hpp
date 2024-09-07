#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
			Contact	contact[8];
	
	public:
			int		add_contact(int index);
			int		search_contact();
};

#endif