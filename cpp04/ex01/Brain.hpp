/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:40 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/12 20:54:55 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain	&operator=(const Brain& other);
};

Brain::Brain()
{
	std::cout << "Constructor Brain called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = "abcd";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor Brain called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}

Brain	&Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i <= 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}
