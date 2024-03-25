/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:20:52 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:28:48 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
