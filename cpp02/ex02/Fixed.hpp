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

	void setRawBits( int const raw );
	int getRawBits( void ) const;

	float toFloat() const;
	int toInt() const;

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;


	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;


	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);


	static Fixed& min( Fixed &a, Fixed &b );
	static const Fixed& min( const Fixed &a, const Fixed &b );
	static Fixed& max( Fixed &a, Fixed &b );
	static const Fixed& max( const Fixed &a, const Fixed &b );
};


std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
