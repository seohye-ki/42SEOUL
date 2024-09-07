#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	std::string		filename;
	std::string		s1;
	std::string		s2;

	if (argc == 4) {
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];

		if (s1.length() == 0 || s2.length() == 0) {
			std::cout << "Wrong arguments." << std::endl;
			return (1);
		}

		std::ifstream	infile(filename.c_str());
		if (!infile.is_open()) {
			std::cout << "File open error." << std::endl;
			return (1);
		}

		std::ofstream	outfile((filename + ".replace").c_str());
		if (!outfile.is_open()) {
			std::cout << "File open error." << std::endl;
			return (1);
		}

		std::string	s;
		size_t		pos;
		getline(infile, s);
		while (infile) {
			pos = 0;
			pos = s.find(s1, pos);
			while (pos != std::string::npos) {
				s.erase(pos, s1.length());
				s.insert(pos, s2);
				pos += s2.length();
				pos = s.find(s1, pos);
			}
			outfile << s;
			getline(infile, s);
			if (infile)
				outfile << std::endl;
		}
		outfile.close();
		infile.close();
	} else {
		std::cout << "Wrong number of parameters." << std::endl;
		return (1);
	}
	return (0);
}