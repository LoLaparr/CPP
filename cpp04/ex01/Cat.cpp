/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:56:13 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 17:56:37 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor Cat called" << std::endl;
	this->_brains = new Brain;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->_type = other._type;
	this->_brains = new Brain;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called" << std::endl;
	if (this->_brains)
		delete this->_brains;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->_brains);
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
		this->_brains = new Brain(*other._brains);
	}
	return (*this);
}
