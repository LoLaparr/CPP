/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:15:16 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/05 15:52:43 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{

	Bureaucrat a("Jean", 150);
	try
	{
		std::cout << a << std::endl;
		a.DecrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}





































// int	main()
// {
// 		{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mLet's create a bureaucrat !\033[0m" << std::endl;
// 		std::cout << std::endl;

// 		Bureaucrat *a = new Bureaucrat("Fabien", 100);
// 		std::cout << std::endl;

// 		std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		std::cout << *a;

// 		try
// 		{
// 			a->IncrementGrade();
// 		}
// 		catch(Bureaucrat::GradeTooHighException &e)
// 		{
// 			std::cerr << "\033[33mIncrementing grade of " << a->GetName() <<
// 			" failed: " << e.what() << "\033[0m" << std::endl;
// 		}

// 		std::cout << *a;

// 		try
// 		{
// 		a->DecrementGrade();
// 		}
// 		catch(Bureaucrat::GradeTooLowException & e)
// 		{
// 			std::cerr << "\033[33mDecrementing grade of " << a->GetName() <<
// 			" failed: " << e.what() << "\033[0m" << std::endl;
// 		}

// 		std::cout << *a;

// 		try
// 		{
// 		a->DecrementGrade();
// 		}
// 		catch(Bureaucrat::GradeTooLowException &e)
// 		{
// 			std::cerr << "\033[33mDecrementing grade of " << a->GetName() <<
// 			" failed: " << e.what() << "\033[0m" << std::endl;
// 		}

// 		std::cout << *a;
// 		std::cout << std::endl;

// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 		delete a;
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat *a = new Bureaucrat(1);
// 		std::cout << std::endl;
// 		std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		std::cout << *a;

// 		try
// 		{
// 		a->DecrementGrade();
// 		}
// 		catch(Bureaucrat::GradeTooLowException &e)
// 		{
// 			std::cerr << "\033[33mDecrementing grade of " << a->GetName() <<
// 			" failed: " << e.what() << "\033[0m" << std::endl;
// 		}

// 		std::cout << *a;

// 		try
// 		{
// 		a->IncrementGrade();
// 		}
// 		catch(Bureaucrat::GradeTooHighException &e)
// 		{
// 			std::cerr << "\033[33mIncrementing grade of " << a->GetName() <<
// 			" failed: " << e.what() << "\033[0m" << std::endl;
// 		}

// 		std::cout << *a;

// 		try
// 		{
// 		a->IncrementGrade();
// 		}
// 		catch(Bureaucrat::GradeTooHighException &e)
// 		{
// 			std::cerr << "\033[33mIncrementing grade of " << a->GetName() <<
// 			" failed: " << e.what() << "\033[0m" << std::endl;
// 		}

// 		std::cout << *a;
// 		std::cout << std::endl;

// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 		delete a;
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat *a = NULL;

// 		try
// 		{
// 			a = new Bureaucrat(0);
// 		}
// 		catch(Bureaucrat::GradeTooHighException &e)
// 		{
// 			std::cerr << "\033[33mConstructing default failed: " <<
// 			e.what() << "\033[0m" << std::endl;
// 		}

// 		if (a != NULL)
// 		{
// 			std::cout << std::endl;

// 			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 			delete a;
// 		}

// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat *a = NULL;

// 		try
// 		{
// 			a = new Bureaucrat(160);
// 		}
// 		catch(Bureaucrat::GradeTooLowException &e)
// 		{
// 			std::cerr << "\033[33mConstructing default failed: " <<
// 			e.what() << "\033[0m" << std::endl;
// 		}

// 		if (a != NULL)
// 		{
// 			std::cout << std::endl;
// 			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 			delete a;
// 		}
// 		std::cout << std::endl;
// 	}
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	{
// 		std::cout << std::endl;
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 		Bureaucrat *a = new Bureaucrat("Peter", 120);
// 		std::cout << std::endl;

// 		std::cout << "\033[34mTesting a\033[0m" << std::endl;
// 		std::cout << *a;

// 		a->DecrementGrade();

// 		std::cout << *a;
// 		std::cout << std::endl;

// 		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
// 		Bureaucrat *b = new Bureaucrat(*a);
// 		std::cout << std::endl;

// 		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
// 		delete a;
// 		std::cout << std::endl;

// 		std::cout << "\033[34mTesting b\033[0m" << std::endl;
// 		std::cout << *b;
// 		b->DecrementGrade();
// 		std::cout << *b;
// 		std::cout << std::endl;

// 		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 		delete b;

// 		std::cout << std::endl;
// 	}

// 	return (0);
// }
