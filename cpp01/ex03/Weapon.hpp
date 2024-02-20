/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:25:55 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 12:25:56 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	type;
public:
	std::string	getType( void )	const;
	void	setType(std::string newType);
	Weapon(std::string Type);
	~Weapon();
};
