#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string Name)
{
	std::cout << "Constructor called" << std::endl;
	this->name = Name;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called" << std::endl;
}
