/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:53:44 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/06 19:20:58 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Hey it's "<< this->_name << " do you want an hight five ?" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	this->_energyPoints -= 1;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

FragTrap::FragTrap()
	 : _name("Default FragTrap")
	 , _hitPoints(100)
	 , _energyPoints(100)
	 , _attackDamage(30)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	 : _name(name)
	 , _hitPoints(100)
	 , _energyPoints(100)
	 , _attackDamage(30)
{
	std::cout << "Default FragTrap constructor with name called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	*this = other;
	std::cout << "Copy constructor of FragTrap called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
