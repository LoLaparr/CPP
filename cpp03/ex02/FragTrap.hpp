/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:53:58 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/06 19:19:38 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	std::string			_name;
	int					_hitPoints;
	int					_energyPoints;
	int					_attackDamage;
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys(void);

	FragTrap &operator=(const FragTrap &other);
};
