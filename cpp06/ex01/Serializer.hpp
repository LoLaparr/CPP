/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:09:31 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/04 15:09:32 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();

	Serializer &operator=(const Serializer &other);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

