/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:27:02 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/25 18:07:37 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string			_name;
	bool				_signed;
	const int			_requiredSign;
	const int			_requiredExec;
	bool				_canI;
public:
	Form();
	Form(std::string name);
	Form(std::string name, int requiredSign, int requiredExec);
	Form(const Form& other);
	virtual ~Form();
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

};

std::ostream &operator<<(std::ostream &out, const Form &Form);
