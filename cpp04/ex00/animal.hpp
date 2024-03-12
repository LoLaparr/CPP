#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& other);
	virtual ~Animal();

	std::string	getType(void) const;

	virtual void	makeSound(void) const;

	Animal &operator=(const Animal& other);
};


Animal::Animal()
{
	std::cout << "Constructor Animal called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Constructor " << this->_type <<" Animal called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor Animal called" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return(this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "makeSound Animal called" << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}
