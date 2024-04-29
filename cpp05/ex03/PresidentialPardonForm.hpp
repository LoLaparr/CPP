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
