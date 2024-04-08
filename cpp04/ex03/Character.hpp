/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:24:59 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:25:16 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character: public ICharacter
{
private:
						Character(void);
	std::string			name;
	int					equipped;
	AMateria			*inventory[4];
public:
						Character(const std::string &name);
						Character(const Character &other);
	virtual				~Character(void);

	const std::string	&getName(void) const;

	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);

	Character			&operator=(const Character &other);
};
