/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:22:01 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/27 15:43:35 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.push_back(i);
	}
	std::list<int> lst;
	for (int i = 6; i <= 10; i++)
	{
		lst.push_back(i);
	}
	try
	{
		std::vector<int>::iterator it1 = easyfind(vec, 3);
		std::cout << "Valeur trouvée à la position (vector) : " << std::distance(vec.begin(),
				it1) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it2 = easyfind(lst, 7);
		std::cout << "Valeur trouvée à la position (list) : " << std::distance(lst.begin(),
				it2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
