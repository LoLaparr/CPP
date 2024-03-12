#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog();
	~Dog();

	void	makeSound(void) const;
};

Dog::Dog() : Animal("Dog")
{
	std::cout << "Constructor Dog called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Animal called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
