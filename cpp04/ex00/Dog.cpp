/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:47:48 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 14:56:23 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructor Dog called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor Dog called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Destructor Animal Dog called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
