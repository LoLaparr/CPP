#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "Constructor default Intern called " << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Copy constructor Intern called" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "Destructor Intern called " << std::endl;
}

static Form *makeNewPresident(std::string target) {
	return (new PresidentialPardonForm(target));
}

static Form *makeNewRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

static Form *makeNewShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNameTab[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	Form *(*formFunct[])(const std::string target) = {&makeNewPresident, &makeNewRobotomy, &makeNewShrubbery};


	try
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (formNameTab[i] == formName)
			{
				std::cout << "Intern creates " << formNameTab[i] << std::endl;
				return (formFunct[i](target));
			}
		}
		throw Intern::BadName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

Intern	&Intern::operator=(const Intern& other) {
	std::cout << "Intern assignation operator called" << std::endl;
	(void)other;
	return (*this);
}

const char	*Intern::BadName::what(void) const throw() {
	return ("Intern exception : Bad Name");
}

