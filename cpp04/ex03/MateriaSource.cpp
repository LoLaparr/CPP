/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:28:09 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:28:30 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): current(0)
{
	for (size_t i = 0; i < 4; i++)
		this->sources[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other): current(0)
{
	for (int i = 0; i < other.current; i++)
		this->learnMateria(other.sources[i]->clone());
	for (size_t i = 0; i < 4; i++)
		this->sources[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->current; i++)
		delete this->sources[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->current  == 4 || m == 0)
		return ;
	for (int i = 0; i < this->current; i++)
	{
		if (this->sources[i] == m)
			return ;
	}
	this->sources[this->current++] = m;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < this->current; i++)
	{
		if (this->sources[i]->getType() == type)
			return (this->sources[i]->clone());
	}
	return (0);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < this->current; i++)
		delete this->sources[i];
	this->current = 0;
	for (int i = 0; i < other.current; i++)
		this->learnMateria(other.sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->sources[i] = 0;
	return (*this);
}
