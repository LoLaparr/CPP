/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:25:23 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:25:24 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string Name, const Weapon &weaPon) : name(Name), weapon(weaPon)
{
    std::cout << "Constructor HumanA called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destructor HumanA called" << std::endl;
}
