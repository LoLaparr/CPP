#pragma once

#include <string>
#include <iostream>

class Fixed
{
private:
	int	_entier;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(int value);
	Fixed(float value);
	~Fixed();
	float	toFloat( void ) const;
	int		toInt( void ) const;
	Fixed&	operator<<();
};

Fixed&	Fixed::operator<<()
{
}

float	toFloat( void) const
{

}

int	toInt( void ) const
{

}

Fixed::Fixed(int value)
{

}

Fixed::Fixed(float value)
{

}

Fixed::Fixed()
{
	std::cout << "Constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

