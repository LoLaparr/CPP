/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:14 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:23:18 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
