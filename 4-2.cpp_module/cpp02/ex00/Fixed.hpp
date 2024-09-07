#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
			int					value;
			static const int	bits = 8;
	public:
			Fixed();
			~Fixed();
			Fixed(const Fixed &obj);
			Fixed& operator=(const Fixed &obj);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif