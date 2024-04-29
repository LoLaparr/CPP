/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:48:09 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/29 16:46:36 by lolaparr         ###   ########.fr       */
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
