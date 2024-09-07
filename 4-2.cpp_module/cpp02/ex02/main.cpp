#include "Fixed.hpp"

int main() {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(5);
	Fixed d(10);

	std::cout << "5 > 10 : " << (c > d) << std::endl;
	std::cout << "5 < 10 : " << (c < d) << std::endl;
	std::cout << "5 == 10 : " << (c == d) << std::endl;
	std::cout << "5 != 10 : " << (c != d) << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}