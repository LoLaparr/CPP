/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:15:16 by lolaparr          #+#    #+#             */
/*   Updated: 2024/04/12 19:31:17 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;
	Form *			simpleDoc = NULL;

	try {
		Donald = new Bureaucrat("Donald", 150);
		Joe = new Bureaucrat("Joe", 1);
		simpleDoc = new Form("Simple Document", 1211, 1);
		simpleDoc->beSigned(*Donald);
		simpleDoc->beSigned(*Joe);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *simpleDoc << std::endl;
	delete Donald;
	delete Joe;
	delete simpleDoc;
	return (0);
}
