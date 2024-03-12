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


WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Constructor " << this->_type <<" WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy constructor WrongAnimal called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return(this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "makeSound WrongAnimal called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}
