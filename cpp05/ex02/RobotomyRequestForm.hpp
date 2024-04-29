#pragma once

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

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};
