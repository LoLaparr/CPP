/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:55:20 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 17:55:57 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

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
