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
#include "AForm.hpp"

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
	std::cout << "Constructor " << this->_name << " Bureaucrat called" << std::endl;
	try
	{
		this->SetGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Copy constructor Bureaucrat called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor " << this->GetName() << " Bureaucrat called " << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat exception: Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat exception: Grade too low");
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

void	Bureaucrat::signAForm(std::string nameForm, bool sign) {
	if (sign == true)
		std::cout << this->GetName() << " signed " << nameForm << std::endl;
	else
		std::cout <<this->GetName() << " couldn’t sign "<< nameForm << " because he hasn't the right grade" << std::endl;
}

void	Bureaucrat::executeForm(AForm const &Form) {
	try {
		Form.execute(*this);
		std::cout << this->GetName() << " executed " << Form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << this->GetName() << " couldn’t executed " << Form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.GetName() << ", Bureaucrat grade " << Bureaucrat.GetGrade() << std::endl;
	return (out);
}
