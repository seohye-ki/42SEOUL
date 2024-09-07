#include "Contact.hpp"
#include <string>
#include <iomanip>

int Contact::is_empty() {
	if (_first_name.empty())
		return (1);
	return (0);
}

void Contact::set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret) {
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_secret = secret;
}

void Contact::show_contact(int index) {
	std::cout << std::setw(10) << std::right << index << "|";
	if (_first_name.length() > 10)
		std::cout << std::setw(9) << std::right << _first_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << _first_name << "|";
	if (_last_name.length() > 10)
		std::cout << std::setw(9) << std::right << _last_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << std::right << _last_name << "|";
	if (_nickname.length() > 10)
		std::cout << std::setw(9) << std::right << _nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << std::right << _nickname << std::endl;
}

void Contact::show_contact_detail() {
	std::cout << "first name: " << _first_name << std::endl;
	std::cout << "last_name: " << _last_name << std::endl;
	std::cout << "nickname: " << _nickname << std::endl;
	std::cout << "phone_number: " << _phone_number << std::endl;
	std::cout << "secret: " << _secret << std::endl;
}