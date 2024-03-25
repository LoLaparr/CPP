/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:36:00 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 14:46:42 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& other);
	virtual ~Animal();

	std::string	getType(void) const;

	virtual void	makeSound(void) const;

	Animal &operator=(const Animal& other);
};
