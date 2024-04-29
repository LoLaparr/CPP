#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Constructor default RobotomyRequestForm called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Constructor with " << target << " RobotomyRequestForm called " << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
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

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return (*this);
}

