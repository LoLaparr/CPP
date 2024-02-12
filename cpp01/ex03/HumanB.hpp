#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon	*weapon;
public:
	void	attack( void );
	void	setWeapon(Weapon &Weapon);
	HumanB(std::string Name);
	~HumanB();
};
