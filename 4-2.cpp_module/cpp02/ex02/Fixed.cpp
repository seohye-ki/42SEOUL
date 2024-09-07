#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	value = num << bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	value = obj.value;
}

Fixed& Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		value = obj.value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (value);
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float Fixed::toFloat(void) const {
	float ret;

	ret = value;
	ret = ret / (1 << bits);
	return (ret);
}

int Fixed::toInt(void) const {
	return (value >> bits);
}

bool Fixed::operator>(const Fixed &obj) const {
 	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const {
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const {
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const {
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const {
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const {
	return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) {
	Fixed ret(this->toFloat() + obj.toFloat());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &obj) {
	Fixed ret(this->toFloat() - obj.toFloat());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &obj) {
	Fixed ret(this->toFloat() * obj.toFloat());
	return (ret);
}

Fixed Fixed::operator/(const Fixed &obj) {
	Fixed ret(this->toFloat() / obj.toFloat());
	return (ret);
}

Fixed& Fixed::operator++() {
	(this->value)++;
	return (*this);
}

Fixed& Fixed::operator--() {
	(this->value)--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	(this->value)++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	(this->value)--;
	return (tmp);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}