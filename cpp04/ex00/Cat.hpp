#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	void	makeSound(void) const;
};

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Destructor Animal called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
