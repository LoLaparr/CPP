/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:47:04 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 14:56:18 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Destructor Animal Cat called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
