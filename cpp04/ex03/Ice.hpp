#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
public:
				Ice(void);
				Ice(const Ice &other);
	virtual		~Ice(void);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);

	Ice			&operator=(const Ice &other);
};

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
