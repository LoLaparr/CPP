/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:24:58 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:24:59 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( size_t N, std::string name )
{
	Zombie *Horde = new Zombie[N];

	for (size_t i = 0; i < N; i++)
	{
		Horde[i].setName(name);
	}
	return (Horde);
}
