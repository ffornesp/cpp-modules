/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:20:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 18:34:47 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

int	main(int argc, char *argv[]) {
	std::string		newFilename;
	std::string		line;
	std::ifstream 	file(argv[1]);

	if (argc != 4)
		return (1);
	newFilename = argv[1];
	newFilename += ".replace";
	if (file.is_open()) {
		std::ofstream	newfile(newFilename);
		while (std::getline(file, line)) {
			if (!line.find(std::string(argv[3]))) { // Creo que hay que iterar la linia para encontrar el word
				std::cout << "Found the word: " << argv[3] << " in line: " << line <<std::endl;
			}
			std::cout << line << std::endl;
		}
		newfile.close();
	}
	file.close();
	return (0);
}