/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:25:49 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:25:50 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string	Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

Weapon::Weapon(std::string Type)
{
	std::cout << "Constructor Weapon called" << std::endl;
	this->type = Type;
}

Weapon::~Weapon()
{
	std::cout << "Destructor Weapon called" << std::endl;
}
