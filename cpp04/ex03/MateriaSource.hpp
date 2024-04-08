/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:27:47 by lolaparr          #+#    #+#             */
/*   Updated: 2024/03/26 17:27:57 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	int				current;
	AMateria		*sources[4];
public:
					MateriaSource(void);
					MateriaSource(const MateriaSource &other);
	virtual			~MateriaSource(void);

	void			learnMateria(AMateria *m);
	AMateria		*createMateria(const std::string &type);

	MateriaSource	&operator=(const MateriaSource &other);
};


