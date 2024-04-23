#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();
	const std::string _target;
public:
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char	*ShrubberyCreationForm::CanNotOpenOutfile::what() const throw()
{
	return("Fail to open the new file");
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (GetSign() == false)
		throw AForm::NotSignedException();
	if (executor.GetGrade() > GetRequiredExec())
		throw AForm::GradeTooLowException();
	std::string fname = _target + "_shrubbery";
	std::cout << "Creating file with name: " << fname << std::endl;
	std::ofstream newFile(fname.c_str());
	if (newFile.fail())
		throw ShrubberyCreationForm::CanNotOpenOutfile();
	if (newFile.is_open())
	{
		newFile << "          &&& &&  & &&" << std::endl;
		newFile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		newFile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		newFile << "   &() &/&|()|/&/ '% & &" << std::endl;
		newFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		newFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		newFile << " ()&_---()\\&\\|&&-&&--%---()~" << std::endl;
		newFile << "     &&    \\|||" << std::endl;
		newFile << "             |||" << std::endl;
		newFile << "             |||" << std::endl;
		newFile << "             |||" << std::endl;
		newFile << "       , -=-~  .-^- _" << std::endl;

		newFile.close();
	}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return (*this);
}
