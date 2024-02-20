/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:24:44 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:24:45 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	size_t	N = 6;
	Zombie	*Horde = zombieHorde(N, "jacques");

	for (size_t i = 0; i < N; i++)
	{
		Horde[i].announce();
	}

	delete[]	Horde;

	return (0);
}
