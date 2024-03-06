/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:52:47 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/06 18:33:33 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ScavTrap	scaav;

	ScavTrap scav("Odin");
	ScavTrap scav2("Floki");
	scaav = scav;
	scav.attack("Floki");
	scav2.takeDamage(500);
	scav2.beRepaired(10);
	scav2.guardGate();
	return (0);
}
