/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:56:51 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 17:57:09 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructor Dog called" << std::endl;
	this->_brains = new Brain;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor Dog called" << std::endl;
	this->_type = other._type;
	this->_brains = new Brain;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
	if (this->_brains)
		delete this->_brains;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->_brains);
}

Dog	&Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
		this->_brains = new Brain(*other._brains);
	}
	return (*this);
}
