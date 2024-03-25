/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:36:15 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:10:36 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* meta = new Animal();
	Animal* dogo = new Dog();
	Animal* cato = new Cat();
	WrongAnimal* wrong = new WrongCat();
	std::cout << std::endl;

	std::cout << dogo->getType() << " " << std::endl;
	std::cout << cato->getType() << " " << std::endl;
	std::cout << std::endl;

	dogo->makeSound();
	cato->makeSound();
	meta->makeSound();
	wrong->makeSound();
	std::cout << std::endl;

	delete meta;
	delete dogo;
	delete cato;
	delete wrong;

	return (0);
}
