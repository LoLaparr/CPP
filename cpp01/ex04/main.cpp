/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:26:01 by lolaparr          #+#    #+#             */
/*   Updated: 2024/02/14 16:12:28 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void	replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	size_t	pos;

	std::ifstream input(filename.c_str());
	if (!input)
	{
		std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
		return ;
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream output(outputFilename.c_str());
	if (!output)
	{
		std::cerr << "Erreur : Impossible de créer le fichier de sortie " << outputFilename << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(input, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		output << line << std::endl;
	}
	input.close();
	output.close();
	std::cout << "Le remplacement est terminé. Le fichier de sortie est : " << outputFilename << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <nom_fichier> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	replaceInFile(filename, s1, s2);
	return (0);
}
