/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:15:16 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/29 16:29:53 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int	main() {
	Bureaucrat *	Donald = new Bureaucrat("Donald", 2);
	Bureaucrat *	Joe = new Bureaucrat("Joe", 10);
	Bureaucrat *	Miguel = new Bureaucrat("Miguel", 65);
	Intern *		nobody = new Intern();
	Form *			shru = new ShrubberyCreationForm("Joe");
	Form *			robot = new RobotomyRequestForm("Donald");
	Form *			ppf = NULL;

	std::cout << std::endl;

	try {
		ppf = nobody->makeForm("PresidentialPardonForm", "Miguel");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try
	{
		if (ppf != NULL)
		{
			ppf->beSigned(*Joe);
			ppf->execute(*Donald);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		robot->beSigned(*Miguel);
		robot->execute(*Donald);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		shru->beSigned(*Joe);
		shru->execute(*Donald);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete ppf;
	delete robot;
	delete shru;
	delete nobody;
	delete Miguel;
	delete Joe;
	delete Donald;

	std::cout << std::endl << std::endl;

	Bureaucrat *	Jack = new Bureaucrat("Jack", 2);
	Bureaucrat *	Martin = new Bureaucrat("Martin", 10);
	Bureaucrat *	Lucy = new Bureaucrat("Lucy", 150);
	Intern *		Nobody = new Intern();
	Form *			Shrubbery = new ShrubberyCreationForm("Martin");
	Form *			Robot = new RobotomyRequestForm("Jack");
	Form *			President = NULL;

	std::cout << std::endl << std::endl;

	try
	{
		President = Nobody->makeForm("Ppp", "Martin");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	try
	{
		if (President != NULL)
		{
			President->beSigned(*Lucy);
			President->execute(*Jack);
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	try
	{
		Robot->beSigned(*Lucy);
		Robot->execute(*Lucy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	try
	{
		Shrubbery->beSigned(*Lucy);
		Shrubbery->execute(*Jack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (President != NULL)
		std::cout << *President << std::endl;
	std::cout << *Robot << std::endl;
	std::cout << *Shrubbery << std::endl;

	delete Jack;
	delete Martin;
	delete Lucy;
	delete Nobody;
	delete Shrubbery;
	delete Robot;
	delete President;

	return (0);
}
