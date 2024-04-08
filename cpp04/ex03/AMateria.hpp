/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:23:08 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:27 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
						AMateria(void);
protected:
	std::string			type;
	unsigned int		xp;
public:
						AMateria(const std::string &type);
						AMateria(const AMateria &other);
	virtual				~AMateria(void);

	const std::string	&getType(void) const;
	unsigned int		getXP(void) const;

	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);

	AMateria			&operator=(const AMateria &other);
};
