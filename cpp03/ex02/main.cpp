/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:12:53 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/06 19:21:02 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ScavTrap scav("Odin");
	scav.attack("target");
	scav.takeDamage(10);
	scav.beRepaired(10);
	scav.guardGate();

	FragTrap frag("Thor");
	frag.attack("target");
	frag.takeDamage(10);
	frag.beRepaired(10);
	frag.highFivesGuys();

	return (0);
}
