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
