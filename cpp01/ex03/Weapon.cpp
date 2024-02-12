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
