/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:16:03 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 17:57:07 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brains;
public:
	Dog();
	Dog(const Dog& other);
	~Dog();

	void	makeSound(void) const;
	Brain	*getBrain() const;

	Dog	&operator=(const Dog& other);
};
