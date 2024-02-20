/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:25:38 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:25:39 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon	*weapon;
public:
	void	attack( void );
	void	setWeapon(Weapon &Weapon);
	HumanB(std::string Name);
	~HumanB();
};
