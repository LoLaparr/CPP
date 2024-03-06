/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:07:47 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/04 18:26:24 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {

		std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

int ClapTrap::get_hitPoints() const
{
	return(this->_hitPoints);
}

int ClapTrap::get_energyPoints() const
{
	return(this->_energyPoints);
}

int ClapTrap::get_attackDamage() const
{
	return(this->_attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (get_hitPoints() <= 0)
		std::cout << this->_name << " ClapTrap can't take damage because is dead" << std::endl;
	else
		std::cout << this->_name << " ClapTrap has taken " << amount << " damage" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << this->_name << " ClapTrap has repaired " << amount << " hit points" << std::endl;
}

ClapTrap::ClapTrap()
	 : _name("Default")
	 , _hitPoints(10)
	 , _energyPoints(10)
	 , _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	 : _name(name)
	 , _hitPoints(10)
	 , _energyPoints(10)
	 , _attackDamage(0)
{
	std::cout << "Default constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
