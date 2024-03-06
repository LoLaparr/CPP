/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:41:25 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/06 18:32:03 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	std::string			_name;
	int					_hitPoints;
	int					_energyPoints;
	int					_attackDamage;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();

	ScavTrap &operator=(const ScavTrap &other);
};
