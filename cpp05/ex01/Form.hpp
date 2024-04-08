/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:27:02 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/08 23:01:32 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_requiredSign;
	const int			_requiredExec;
	bool				_canI;
public:
	Form();
	Form(std::string name);
	Form(std::string name, int requiredSign, int requiredExec);
	Form(const Form& other);
	~Form();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	std::string	GetName() const;
	bool				GetSign() const;
	int			GetRequiredSign() const;
	int			GetRequiredExec() const;

	void	checkSign(int requiredSign);
	void	checkExec(int requiredExec);

	void	beSigned(Bureaucrat &bureaucrat);

	Form &operator=(const Form& other);
};
std::ostream &operator<<(std::ostream &out, const Form &form);

Form::Form() : _name("default"), _signed(false), _requiredSign(1), _requiredExec(1), _canI(false)
{
	std::cout << "Constructor default Form called " << std::endl;
	try
	{
		this->checkSign(this->_requiredSign);
		this->checkExec(this->_requiredExec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

Form::Form(std::string name) : _name(name), _signed(false), _requiredSign(1), _requiredExec(1), _canI(false)
{
	std::cout << "Constructor by name Form called " << std::endl;
	try
	{
		this->checkSign(this->_requiredSign);
		this->checkExec(this->_requiredExec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

Form::Form(std::string name, int requiredSign, int requiredExec) : _name(name), _signed(false), _requiredSign(requiredSign), _requiredExec(requiredExec), _canI(false)
{
	std::cout << "Constructor without name Form called " << std::endl;
	try
	{
		checkSign(requiredSign);
		checkExec(requiredExec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

Form	&Form::operator=(const Form& other) {
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &other)
	{
		_signed = other.GetSign();
	}
	return (*this);
}

Form::Form(const Form& other) : _name(other.GetName()), _requiredSign(other.GetRequiredSign()), _requiredExec(other.GetRequiredExec()), _canI(false)
{
	std::cout << "Copy constructor Form called " << std::endl;
	*this = other;
}

Form::~Form()
{
	std::cout << "Destructor "<< this->GetName() << " Form called " << std::endl;
}

std::string	Form::GetName() const {
	return (this->_name);
}

bool	Form::GetSign() const {
	return (this->_signed);
}

int	Form::GetRequiredSign() const {
	return (this->_requiredSign);
}

int	Form::GetRequiredExec() const {
	return (this->_requiredExec);
}

void	Form::checkSign(int requiredSign) {
	if (requiredSign > 150)
		throw Form::GradeTooLowException();
	else if (requiredSign < 1)
		throw Form::GradeTooHighException();
	else
	{
		this->_canI = true;
		return;
	}
}

void	Form::checkExec(int requiredExec) {
	if (requiredExec > 150)
		throw Form::GradeTooLowException();
	else if (requiredExec < 1)
		throw Form::GradeTooHighException();
	else
	{
		this->_canI = true;
		return;
	}
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (this->_canI == false)
	{
		std::cout << "The grade dosen't exist to be sign" << std::endl;
		return;
	}
	else if ((bureaucrat.GetGrade() <= this->GetRequiredSign()))
	{
		this->_signed = true;
		bureaucrat.signForm(this->GetName(), this->_signed);
	}
	else if (this->_signed == true)
	{
		std::cout << "This Form has been signed" << std::endl;
		return;
	}
	else
	{
		bureaucrat.signForm(this->GetName(), this->_signed);
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << std::endl << "Name: " << form.GetName() << "\n"
			<< "Signed: " << (form.GetSign() == true ? "yes" : "no") << std::endl
			<< "Grade to sign: " << form.GetRequiredSign() << std::endl
			<< "Grade to execute: " << form.GetRequiredExec() << std::endl
			<< std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Form exception: grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Form exception: grade too low");
}
