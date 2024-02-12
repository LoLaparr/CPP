#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	const Weapon	&weapon;
public:
	void	attack( void );
	HumanA(std::string Name, const Weapon &weaPon);
	~HumanA();
};
