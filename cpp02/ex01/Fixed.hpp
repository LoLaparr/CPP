#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;

public:

	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	float toFloat() const;
	int toInt() const;

	Fixed &operator=(const Fixed &other);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
