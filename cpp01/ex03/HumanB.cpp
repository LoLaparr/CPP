#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->weapon = &Weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their "<< this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string Name) : name(Name), weapon(NULL)
{
	std::cout << "Constructor HumanB called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destructor HumanB called" << std::endl;
}
