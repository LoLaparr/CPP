/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:15:26 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/05 15:28:41 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::IncrementGrade()
{
	try
	{
		this->SetGrade(this->_grade - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::DecrementGrade()
{
	try
	{
		this->SetGrade(this->_grade + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::SetGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Constructor default Bureaucrat called " << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default")
{
	std::cout << "Constructor grade " << this->_name << " Bureaucrat called" << std::endl;
	try
	{ 
		this->SetGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		this->SetGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Constructor " << this->_name << " Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Copy constructor Bureaucrat called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called " << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const std::string	Bureaucrat::GetName() const
{
	return (this->_name);
}

int	Bureaucrat::GetGrade() const
{
	return (this->_grade);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &other)
	{
		_grade = other.GetGrade();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.GetName() << ", Bureaucrat grade " << Bureaucrat.GetGrade() << std::endl;
	return (out);
}

