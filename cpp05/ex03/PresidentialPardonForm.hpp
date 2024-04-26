#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
	const std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;

	PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);
};

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "Constructor default PresidentialPardonForm called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Constructor with " << target << " PresidentialPardonForm called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other), _target(other._target)
{
	std::cout << "Copy constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor PresidentialPardonForm called " << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	executor.executeForm(*this);
	if (GetSign() == false)
		throw Form::NotSignedException();
	if (executor.GetGrade() > GetRequiredExec())
		throw Form::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	(void)other;
	return (*this);
}
