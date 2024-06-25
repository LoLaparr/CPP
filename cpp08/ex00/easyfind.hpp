/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:22:05 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/19 15:07:23 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it =
		std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::length_error("the list does not contain your object");
	return (it);
}
