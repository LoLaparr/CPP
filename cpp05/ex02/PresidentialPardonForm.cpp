#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "Constructor default PresidentialPardonForm called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Constructor with " << target << " PresidentialPardonForm called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
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
		throw AForm::NotSignedException();
	if (executor.GetGrade() > GetRequiredExec())
		throw AForm::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

