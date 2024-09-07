#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++) {
			std::string msg = argv[i];
			for (size_t j = 0; j < msg.length(); j++) {
				msg[j] = toupper(msg[j]);
			}
			std::cout << msg;
		}
		std::cout << std::endl;
	}
	return (0);
}