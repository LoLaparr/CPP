#pragma once

#include <iostream>
#include <string>

class Buraucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Buraucrat();
	Buraucrat(std::string name, int grade);
	Buraucrat(const Buraucrat& other);
	~Buraucrat();

	const std::string	GetName() const;
	int					GetGrade() const;

	Buraucrat &operator=(const Buraucrat& other);
};

Buraucrat::Buraucrat()
{
	std::cout << "Constructor Buraucrat called " << std::endl;
}

Buraucrat::Buraucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor " << this->_name << "Buraucrat called" << std::endl;
}

Buraucrat::Buraucrat(const Buraucrat& other)
{
	std::cout << "Copy constructor Buraucrat called" << std::endl;
	*this = other;
}

Buraucrat::~Buraucrat()
{
	std::cout << "Destructor Buraucrat called " << std::endl;
}

const std::string	Buraucrat::GetName() const
{
	return (this->_name);
}

int	Buraucrat::GetGrade() const
{
	return (this->_grade);
}

Buraucrat	&Buraucrat::operator=(const Buraucrat& other)
{
	std::cout << "Buraucrzt assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
}
