/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:26:48 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:27:00 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
public:
				Ice(void);
				Ice(const Ice &other);
	virtual		~Ice(void);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);

	Ice			&operator=(const Ice &other);
};
