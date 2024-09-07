#include "PhoneBook.hpp"

int main() {
	PhoneBook	phonebook;
	std::string	cmd;
	int			index = 0;

	while (1) {
		std::cout << "ADD 또는 SEARCH 또는 EXIT 중 하나를 입력하세요." << std::endl;
		std::getline(std::cin, cmd, '\n');
		if (std::cin.fail())
			return (1);
		if (cmd == "ADD") {
			int result = phonebook.add_contact(index);
			if (result == 0)
				index++;
			else if (result == 1) {
				std::cout << "<<<<<<<<<<<< error >>>>>>>>>>>>" << std::endl;
				return (1);
			}
		}
		else if (cmd == "SEARCH") {
			int result = phonebook.search_contact();
			if (result == 1) {
				std::cout << "<<<<<<<<<<<< error >>>>>>>>>>>>" << std::endl;
				return (1);
			}
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "존재하지 않는 명령어입니다." << std::endl;
	}
	return (0);
}