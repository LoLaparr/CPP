#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	class CanNotOpenOutfile : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};

	void	execute(Bureaucrat const &executor) const;

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};
