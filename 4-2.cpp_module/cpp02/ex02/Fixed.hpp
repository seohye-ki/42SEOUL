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
			
			bool	operator>(const Fixed &obj) const;
			bool	operator<(const Fixed &obj) const;
			bool	operator>=(const Fixed &obj) const;
			bool	operator<=(const Fixed &obj) const;
			bool	operator==(const Fixed &obj) const;
			bool	operator!=(const Fixed &obj) const;

			Fixed	operator+(const Fixed &obj);
			Fixed	operator-(const Fixed &obj);
			Fixed	operator*(const Fixed &obj);
			Fixed	operator/(const Fixed &obj);
			
			Fixed&	operator++();
			Fixed&	operator--();
			Fixed	operator++(int);
			Fixed	operator--(int);

			static Fixed&		max(Fixed &a, Fixed &b);
			static const Fixed&	max(const Fixed &a, const Fixed &b);
			static Fixed&		min(Fixed &a, Fixed &b);
			static const Fixed&	min(const Fixed &a, const Fixed &b);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif