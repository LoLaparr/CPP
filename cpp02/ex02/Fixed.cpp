#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return(_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}


Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->_value + other._value));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->_value - other._value));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}


Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed &Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
	if ( a.getRawBits() < b.getRawBits() )
		return a;
	return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
	if ( a.getRawBits() > b.getRawBits() )
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}
