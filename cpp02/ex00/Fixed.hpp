/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:55:37 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/28 14:23:51 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Fixed
{
private:
	int	_value;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();
	Fixed& operator=(const Fixed& other);
	void setRawBits( int const raw );
	int getRawBits( void ) const;
};
