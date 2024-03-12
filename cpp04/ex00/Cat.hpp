#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat();
	~Cat();

	void	makeSound(void) const;
};

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor Animal called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
