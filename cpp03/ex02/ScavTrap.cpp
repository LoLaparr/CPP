#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	 : _name("Default ScavTrap")
	 , _hitPoints(100)
	 , _energyPoints(50)
	 , _attackDamage(20)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	 : _name(name)
	 , _hitPoints(100)
	 , _energyPoints(50)
	 , _attackDamage(20)
{
	std::cout << "Default ScavTrap constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap : " << this->_name << "  is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}
