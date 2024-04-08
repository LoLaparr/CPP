/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:24:27 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:26:39 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): type(type), xp(0)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType(void) const
{
	return (this->type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->xp);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	this->xp += 10;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->xp = other.getXP();
	this->type = other.getType();
	return (*this);
}

