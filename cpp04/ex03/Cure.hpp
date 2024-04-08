/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:25:55 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:26:12 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
class ICharacter;
# include "AMateria.hpp"

class Cure: public AMateria
{
public:
				Cure(void);
				Cure(const Cure &other);
	virtual		~Cure(void);

	AMateria	*clone(void) const;
	void		use(ICharacter &target);

	Cure		&operator=(const Cure &other);
};
