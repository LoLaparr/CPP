#pragma once

#include <iostream>
#include <string>

class animal
{
protected:
	std::string type;
public:
	animal();
	animal(const animal& other);
	~animal();

	animal &operator=(const animal& other);
};

animal	&animal::operator=(const animal& other)
{
	std::cout << "animal assignation operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

animal::animal()
{
}

animal::animal(const animal& other)
{
	std::cout << "Copy constructor animal called" << std::endl;
	*this = other;
}

animal::~animal()
{
}

