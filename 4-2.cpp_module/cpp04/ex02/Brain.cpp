#include "Brain.hpp"

Brain::Brain() {
	std::cout << "This is Brain!" << std::endl;
	idea[0] = "i don't have idea";
}

Brain::~Brain() {
	std::cout << "Destory Brain!" << std::endl;
}

Brain::Brain(const Brain &obj) {
	*this = obj;
}

Brain& Brain::operator=(const Brain &obj) {
	if (this != &obj) {
		for (int i = 0; i < 100; i++)
			idea[i] = obj.idea[i] + " stolen";
	}
	return *this;
}

std::string Brain::getIdea(int index) {
	return idea[index];
}

void Brain::setIdea(int index, std::string str) {
	idea[index] = str;
}
