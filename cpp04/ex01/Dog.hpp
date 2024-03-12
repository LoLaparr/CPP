#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brains;
public:
	Dog();
	Dog(const Dog& other);
	~Dog();

	void	makeSound(void) const;
	Brain	*getBrain() const;

	Dog	&operator=(const Dog& other);
};

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructor Dog called" << std::endl;
	this->_brains = new Brain;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor Dog called" << std::endl;
	this->_type = other._type;
	this->_brains = new Brain;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
	if (this->_brains)
		delete this->_brains;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->_brains);
}

Dog	&Dog::operator=(const Dog& other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}
