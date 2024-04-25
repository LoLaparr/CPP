/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:48:09 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/25 18:36:33 by lolaparr         ###   ########.fr       */
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

	for (size_t i = 0; i < 3; i++)
	{
		if (formNameTab[i] == formName)
		{
			std::cout << "Intern creates " << formNameTab[i] << std::endl;
			return (formFunct[i](target));
		}
	}
	return (NULL);
}

Intern	&Intern::operator=(const Intern& other) {
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &other)
	{
		this = &other;
	}
	return (*this);
}
