/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:19:22 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:19:54 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal& other);
	virtual ~AAnimal();

	std::string	getType(void) const;

	virtual void	makeSound(void) const = 0;

	AAnimal &operator=(const AAnimal& other);
};
