/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:48:09 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/26 19:08:24 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	class BadName : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	Form	*makeForm(const std::string& formName, const std::string& target);

	Intern&	operator=(const Intern &other);
};

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern()
{
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
