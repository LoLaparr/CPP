#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string	GetTarget() const;

	void	execute(Bureaucrat const &executor) const;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Constructor default RobotomyRequestForm called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Constructor with " << target << " RobotomyRequestForm called " << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other), _target(other._target)
{
	std::cout << "Copy constructor RobotomyRequestForm called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor RobotomyRequestForm called " << std::endl;
}

std::string	RobotomyRequestForm::GetTarget() const
{
	return(this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	executor.executeForm(*this);
	if (this->GetSign() == false)
		throw NotSignedException();
	if (executor.GetGrade() > this->GetRequiredExec())
		throw GradeTooLowException();
	else
	{
		static int rand = 0;
		if (rand % 2 == 0)
			std::cout << "Success " << this->GetTarget() << " has been robotomized" << std::endl;
		else
			++rand;
	}
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	(void)other;
	return (*this);
}
