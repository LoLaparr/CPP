#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	~WrongCat();

	void	makeSound(void) const;
};

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
