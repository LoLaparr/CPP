#pragma once

# include <string>
class ICharacter;
# include "AMateria.hpp"

class Cure: public AMateria
{
public:
				Cure(void);
				Cure(const Cure &other);
	virtual		~Cure(void);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);

	Cure		&operator=(const Cure &other);
};

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	this->xp = other.xp;
}

Cure::~Cure()
{
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	this->xp = other.xp;
	return (*this);
}
