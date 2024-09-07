#include "PhoneBook.hpp"
#include <sstream>

int PhoneBook::add_contact(int index) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
	
	std::cout << "1. first name을 입력해주세요." << std::endl;
	std::getline(std::cin, first_name, '\n');
	if (std::cin.fail())
		return (1);
	else if (first_name.empty())
		return (2);
	std::cout << "2. last name을 입력해주세요." << std::endl;
	std::getline(std::cin, last_name, '\n');
	if (std::cin.fail())
		return (1);
	else if (last_name.empty())
		return (2);
	std::cout << "3. nickname을 입력해주세요." << std::endl;
	std::getline(std::cin, nickname, '\n');
	if (std::cin.fail())
		return (1);
	else if (nickname.empty())
		return (2);
	std::cout << "4. phone number을 입력해주세요." << std::endl;
	std::getline(std::cin, phone_number, '\n');
	if (std::cin.fail())
		return (1);
	else if (phone_number.empty())
		return (2);
	std::cout << "5. dark secret을 입력해주세요." << std::endl;
	std::getline(std::cin, secret, '\n');
	if (std::cin.fail())
		return (2);
	else if (secret.empty())
		return (1);
	contact[index % 8].set_contact(first_name, last_name, nickname, phone_number, secret);
	return (0);
}

int PhoneBook::search_contact() {
	if (contact[0].is_empty()) {
		std::cout << "저장된 연락처가 없습니다." << std::endl;
		return (0);
	}

	for (int i = 0; i < 8; i++) {
		if (contact[i].is_empty() == 0)
			contact[i].show_contact(i);
	}

	std::string			s;
	std::cout << "몇번째 연락처를 보고싶으신가요?" << std::endl;
	std::getline(std::cin, s, '\n');
	if (std::cin.fail())
		return (1);

	std::stringstream	ss(s);
	int					index;
	ss >> index;
	if (ss.eof()) {
		if (index >= 8 || index < 0 || contact[index].is_empty())
			std::cout << "없는 연락처입니다." << std::endl;
		else
			contact[index].show_contact_detail();
	}
	else
		std::cout << "없는 연락처입니다." << std::endl;
	return (0);
}