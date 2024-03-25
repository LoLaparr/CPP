/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:16:07 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 17:56:34 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brains;
public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	void	makeSound(void) const;
	Brain	*getBrain() const;

	Cat	&operator=(const Cat& other);
};
