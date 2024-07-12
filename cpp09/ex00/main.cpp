/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:44:08 by hrobin            #+#    #+#             */
/*   Updated: 2024/07/10 15:51:52 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int	main(int ac, char **av)
{
	try {
		BitcoinExchange bitcoin( ac, av[1] );
		bitcoin.processAndDisplay();
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
