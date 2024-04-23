#include pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string	GetTarget() const;

	void	execute(Bureaucrat const &executor) const;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other)
};

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string	RobotomyRequestForm::GetTarget() const
{
	return(this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
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
