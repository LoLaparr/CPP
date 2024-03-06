/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:49:55 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/06 18:30:40 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cmath>

class ClapTrap
{
private:
	std::string			_name;
	int					_hitPoints;
	int					_energyPoints;
	int					_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	int			get_hitPoints() const;
	int			get_energyPoints() const;
	int			get_attackDamage() const;


	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
virtual	void attack(const std::string& target);

	ClapTrap &operator=(const ClapTrap &other);
};


