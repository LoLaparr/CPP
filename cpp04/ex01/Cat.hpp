#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *_brains;
public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	void	makeSound(void) const;
	Brain	*getBrain() const;

	Cat	&operator=(const Cat& other);
};

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor Cat called" << std::endl;
	this->_brains = new Brain;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->_type = other._type;
	this->_brains = new Brain;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called" << std::endl;
	if (this->_brains)
		delete this->_brains;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->_brains);
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}
