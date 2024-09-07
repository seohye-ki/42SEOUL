#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
			int					value;
			static const int	bits = 8;
	public:
			Fixed();
			Fixed(const int num);
			Fixed(const float num);
			~Fixed();
			Fixed(const Fixed &obj);
			Fixed& operator=(const Fixed &obj);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif