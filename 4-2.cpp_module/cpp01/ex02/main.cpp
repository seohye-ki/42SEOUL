#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "str pointer address: " << &stringPTR << std::endl;
	std::cout << "str reference address: " << &stringREF << std::endl; 
	std::cout << "==============================================" << std::endl;
	std::cout << "str value: " << str << std::endl;
	std::cout << "str pointer value: " << *stringPTR << std::endl;
	std::cout << "str reference value: " << stringREF << std::endl; 
}