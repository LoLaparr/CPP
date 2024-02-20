/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:55:58 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/20 17:40:05 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _entier(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_entier);
}

void	Fixed::setRawBits( int const raw )
{
	this->_entier = raw;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignement called" << std::endl;
	if (this != &other)
	{
		this->_entier = other.getRawBits();
	}
	return (*this);
}

