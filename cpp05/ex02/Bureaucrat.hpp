/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:11:28 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/05 15:11:29 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	const std::string	GetName() const;
	int					GetGrade() const;

	void	SetGrade(int grade);

	void	IncrementGrade();
	void	DecrementGrade();

	void	signAForm(std::string, bool);
	void	executeForm(AForm const &Form);

	Bureaucrat &operator=(const Bureaucrat& other);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

