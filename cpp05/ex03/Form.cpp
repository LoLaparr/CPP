
#include "Form.hpp"
#include "Bureaucrat.hpp"

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
		std::cerr << e.what() << std::endl;
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
		std::cerr << e.what() << std::endl;
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

Form::Form(const Form& other) : _name(other.getName()), _requiredSign(other.GetRequiredSign()), _requiredExec(other.GetRequiredExec()), _canI(false)
{
	std::cout << "Copy constructor Form called " << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor "<< this->getName() << " Form called " << std::endl;
}

std::string	Form::getName() const {
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

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_canI == false)
	{
		std::cout << "The grade dosen't exist to be sign" << std::endl;
		return;
	}
	else if ((bureaucrat.GetGrade() <= this->GetRequiredSign()))
	{
		this->_signed = true;
		bureaucrat.signForm(this->getName(), this->_signed);
	}
	else if (this->_signed == true)
	{
		std::cout << "This Form has been signed" << std::endl;
		return;
	}
	else
	{
		bureaucrat.signForm(this->getName(), this->_signed);
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &Form) {
	out << std::endl << "Name: " << Form.getName() << std::endl
			<< "Signed: " << (Form.GetSign() == true ? "yes" : "no") << std::endl
			<< "Grade to sign: " << Form.GetRequiredSign() << std::endl
			<< "Grade to execute: " << Form.GetRequiredExec() << std::endl
			<< std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Form exception: grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Form exception: grade too low");
}

const char *Form::NotSignedException::what(void) const throw() {
		return("Form exception: Form was not signed");
}
