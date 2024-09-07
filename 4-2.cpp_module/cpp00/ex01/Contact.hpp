#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	private:
			std::string	_first_name;
			std::string	_last_name;
			std::string	_nickname;
			std::string	_phone_number;
			std::string	_secret;

	public:
			int		is_empty();
			void	set_contact(std::string first_name,
								std::string last_name,
								std::string nickname,
								std::string phone_number,
								std::string secret);
			void	show_contact(int index);
			void	show_contact_detail();
};

#endif