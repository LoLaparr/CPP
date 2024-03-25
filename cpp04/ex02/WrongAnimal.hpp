#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
private:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();

	std::string	getType(void) const;

	virtual void	makeSound(void) const;

	WrongAnimal &operator=(const WrongAnimal& other);
};
