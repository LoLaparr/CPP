/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:24:54 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:24:55 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void	announce( void );
	void	setName(std::string name);
	Zombie();
	~Zombie();
};

Zombie	*zombieHorde( size_t N, std::string name );
Zombie	*newZombie(std::string name);
