
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _requiredSign(1), _requiredExec(1), _canI(false)
{
	std::cout << "Constructor default AForm called " << std::endl;
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

AForm::AForm(std::string name) : _name(name), _signed(false), _requiredSign(1), _requiredExec(1), _canI(false)
{
	std::cout << "Constructor by name AForm called " << std::endl;
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

AForm::AForm(std::string name, int requiredSign, int requiredExec) : _name(name), _signed(false), _requiredSign(requiredSign), _requiredExec(requiredExec), _canI(false)
{
	std::cout << "Constructor without name AForm called " << std::endl;
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

AForm	&AForm::operator=(const AForm& other) {
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &other)
	{
		_signed = other.GetSign();
	}
	return (*this);
}

AForm::AForm(const AForm& other) : _name(other.getName()), _requiredSign(other.GetRequiredSign()), _requiredExec(other.GetRequiredExec()), _canI(false)
{
	std::cout << "Copy constructor AForm called " << std::endl;
	*this = other;
}

AForm::~AForm()
{
	std::cout << "Destructor "<< this->getName() << " AForm called " << std::endl;
}

std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::GetSign() const {
	return (this->_signed);
}

int	AForm::GetRequiredSign() const {
	return (this->_requiredSign);
}

int	AForm::GetRequiredExec() const {
	return (this->_requiredExec);
}

void	AForm::checkSign(int requiredSign) {
	if (requiredSign > 150)
		throw AForm::GradeTooLowException();
	else if (requiredSign < 1)
		throw AForm::GradeTooHighException();
	else
	{
		this->_canI = true;
		return;
	}
}

void	AForm::checkExec(int requiredExec) {
	if (requiredExec > 150)
		throw AForm::GradeTooLowException();
	else if (requiredExec < 1)
		throw AForm::GradeTooHighException();
	else
	{
		this->_canI = true;
		return;
	}
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_canI == false)
	{
		std::cout << "The grade dosen't exist to be sign" << std::endl;
		return;
	}
	else if ((bureaucrat.GetGrade() <= this->GetRequiredSign()))
	{
		this->_signed = true;
		bureaucrat.signAForm(this->getName(), this->_signed);
	}
	else if (this->_signed == true)
	{
		std::cout << "This AForm has been signed" << std::endl;
		return;
	}
	else
	{
		bureaucrat.signAForm(this->getName(), this->_signed);
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
	out << std::endl << "Name: " << AForm.getName() << std::endl
			<< "Signed: " << (AForm.GetSign() == true ? "yes" : "no") << std::endl
			<< "Grade to sign: " << AForm.GetRequiredSign() << std::endl
			<< "Grade to execute: " << AForm.GetRequiredExec() << std::endl
			<< std::endl;
	return (out);
}

const char* AForm::GradeTooHighException::what(void) const throw() {
	return ("AForm exception: grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("AForm exception: grade too low");
}

const char *AForm::NotSignedException::what(void) const throw() {
		return("AForm exception: AForm was not signed");
}
