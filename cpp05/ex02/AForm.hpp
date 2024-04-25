/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:27:02 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/12 19:26:20 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string			_name;
	bool				_signed;
	const int			_requiredSign;
	const int			_requiredExec;
	bool				_canI;
public:
	AForm();
	AForm(std::string name);
	AForm(std::string name, int requiredSign, int requiredExec);
	AForm(const AForm& other);
	~AForm();
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
	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	std::string			getName() const;
	bool				GetSign() const;
	int			GetRequiredSign() const;
	int			GetRequiredExec() const;

	void	checkSign(int requiredSign);
	void	checkExec(int requiredExec);

	void	beSigned(Bureaucrat& bureaucrat);

	virtual void execute(const Bureaucrat &executor) const = 0;

	AForm &operator=(const AForm& other);
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);
