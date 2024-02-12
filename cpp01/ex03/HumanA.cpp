#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string Name, const Weapon &weaPon) : name(Name), weapon(weaPon)
{
    std::cout << "Constructor HumanA called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destructor HumanA called" << std::endl;
}
