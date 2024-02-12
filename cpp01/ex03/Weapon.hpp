#pragma once

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	type;
public:
	std::string	getType( void )	const;
	void	setType(std::string newType);
	Weapon(std::string Type);
	~Weapon();
};
