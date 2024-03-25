/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:26:50 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:27:11 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
