/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:15:16 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/25 16:57:21 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main() {
	Bureaucrat *	Donald = new Bureaucrat("Donald", 2);
	Bureaucrat *	Joe = new Bureaucrat("Joe", 10);
	Bureaucrat *	Miguel = new Bureaucrat("Miguel", 60);
	AForm *			shru = new ShrubberyCreationForm("Joe");
	AForm *			robot = new RobotomyRequestForm("Donald");
	AForm *			president = new PresidentialPardonForm("Miguel");

	try {
		president->beSigned(*Joe);
		president->execute(*Donald);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try
	{
		robot->beSigned(*Miguel);
		robot->execute(*Donald);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		shru->beSigned(*Joe);
		shru->execute(*Donald);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << *president << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *shru << std::endl;

	delete robot;
	delete shru;
	delete Miguel;
	delete Joe;
	delete Donald;

	std::cout << std::endl << std::endl;

	Bureaucrat *	Jack = new Bureaucrat("Jack", 2);
	Bureaucrat *	Martin = new Bureaucrat("Martin", 10);
	Bureaucrat *	Lucy = new Bureaucrat("Lucy", 120);
	AForm *			Shrubbery = new ShrubberyCreationForm("Martin");
	AForm *			Robot = new RobotomyRequestForm("Jack");
	AForm *			President = new PresidentialPardonForm("Lucy");

	try {
		President->beSigned(*Lucy);
		President->execute(*Jack);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Robot->beSigned(*Jack);
		Robot->execute(*Lucy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Shrubbery->beSigned(*Martin);
		Shrubbery->execute(*Jack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << *President << std::endl;
	std::cout << *Robot << std::endl;
	std::cout << *Shrubbery << std::endl;

	delete robot;
	delete shru;
	delete Miguel;
	delete Joe;
	delete Donald;
}
