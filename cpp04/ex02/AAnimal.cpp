/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:19:34 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:19:56 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Constructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Constructor " << this->_type <<" AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Copy constructor AAnimal called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor AAnimal called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return(this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "makeSound AAnimal called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}
