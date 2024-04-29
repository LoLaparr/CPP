/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:27:02 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/29 16:37:03 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_requiredSign;
	const int			_requiredExec;
	bool				_canI;
public:
	Form();
	Form(std::string name);
	Form(std::string name, int requiredSign, int requiredExec);
	Form(const Form& other);
	~Form();
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

	std::string	GetName() const;
	bool				GetSign() const;
	int			GetRequiredSign() const;
	int			GetRequiredExec() const;

	void	checkSign(int requiredSign);
	void	checkExec(int requiredExec);

	void	beSigned(Bureaucrat &bureaucrat);

	Form &operator=(const Form& other);
};
std::ostream &operator<<(std::ostream &out, const Form &form);
