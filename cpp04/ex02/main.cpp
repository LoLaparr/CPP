/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:15:17 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:12:08 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <iostream>

#define NBR_ANIMALS 4


int main(void)
{
	AAnimal* dogo = new Dog();
	
	std::cout << std::endl;

	AAnimal* cato = new Cat();

	std::cout << std::endl;

	std::cout << dogo->getType() << " " << std::endl;
	std::cout << cato->getType() << " " << std::endl;

	std::cout << std::endl;

	dogo->makeSound();
	cato->makeSound();

	std::cout << std::endl;

	delete dogo;
	delete cato;

	std::cout << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;

	AAnimal* zoo[NBR_ANIMALS];

	for (size_t i = 0; i < 2; i += 1) {
		zoo[i] = new Dog();
		std::cout << std::endl;
	}

	for (size_t i = 2; i < 4; i += 1) {
		zoo[i] = new Cat();
		std::cout << std::endl;
	}

	for (size_t i = 0; i < NBR_ANIMALS; i+= 1) {
		zoo[i]->makeSound();
	}
	std::cout << std::endl;

	for (size_t i = 0; i < NBR_ANIMALS; i += 1) {
		delete zoo[i];
		std::cout << std::endl;
	}

	return (0);
}
