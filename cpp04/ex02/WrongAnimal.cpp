/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:26:12 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:26:34 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Constructor " << this->_type <<" WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy constructor WrongAnimal called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return(this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "makeSound WrongAnimal called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}
