#pragma once

# include <iostream>
# include <string>
class AMateria;
# include "ICharacter.hpp"

class AMateria
{
private:
						AMateria(void);
protected:
	std::string			type;
	unsigned int		xp;
public:
						AMateria(const std::string &type);
						AMateria(const AMateria &other);
	virtual				~AMateria(void);

	const std::string	&getType(void) const;
	unsigned int		getXP(void) const;

	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);

	AMateria			&operator=(const AMateria &other);
};

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
