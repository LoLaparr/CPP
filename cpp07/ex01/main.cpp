/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:34:18 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/06 16:36:28 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print_char(char &c) {
	std::cout << c;
}

int main() {
	char arr[] = "Hello World!";

	iter(arr, sizeof(arr), print_char);
	std::cout << std::endl;
}
