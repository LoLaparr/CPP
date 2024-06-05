/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:08:24 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/04 15:08:25 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./convert <value>" << std::endl;
		std::cout << "Example: ./convert 42.4f" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	return (0);
}
