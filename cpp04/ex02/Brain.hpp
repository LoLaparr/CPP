/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:40 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/25 18:20:29 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain	&operator=(const Brain& other);
};
