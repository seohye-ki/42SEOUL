#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
			std::string	idea[100];
	public:
			Brain();
			~Brain();
			Brain(const Brain& obj);
			Brain& operator=(const Brain& obj);
			std::string	getIdea(int index);
			void		setIdea(int index, std::string str);
};

#endif
