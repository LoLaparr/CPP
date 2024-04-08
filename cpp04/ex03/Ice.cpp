/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:27:13 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:27:22 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(const Ice &other): AMateria("ice")
{
	this->xp = other.xp;
}

Ice::~Ice()
{
}


AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout <<"* shoots an ice bolt at " << target.getName()<< " *" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	this->xp = other.xp;
	return (*this);
}

