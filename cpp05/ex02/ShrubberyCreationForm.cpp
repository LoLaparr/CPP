#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Constructor default ShrubberyCreationForm called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Constructor with " << target << " ShrubberyCreationForm called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "Copy constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor ShrubberyCreationForm called " << std::endl;
}

const char	*ShrubberyCreationForm::CanNotOpenOutfile::what() const throw()
{
	return("Fail to open the new file");
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	executor.executeForm(*this);
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

