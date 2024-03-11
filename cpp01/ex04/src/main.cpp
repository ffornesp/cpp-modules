/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:20:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 12:32:13 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

static int	errorMessage(std::string error, int errorId) {
	std::cout << "Error: ";
	std::cout << error << std::endl;
	return (errorId);
}

static int	checkArgs(int argc, char *argv[]) {
	std::string	aux;

	if (argc != 4)
		return (errorMessage("Usage: ./executable file string_to_replace new_string", 1));
	for (size_t i = 0; i < (size_t)argc; i++) {
		if (!argv[i])
			return (errorMessage("Invalid arguments", 1));
		aux = argv[i];
		if (aux.empty())
			return (errorMessage("Invalid arguments", 1));
	}
	return (0);
}

static void	replaceStr(std::string line, std::ofstream&	output, std::string old_str, std::string new_str) {
	size_t	pos;

	pos = line.find(old_str);
	while (pos != std::string::npos) {
		line.erase(pos, old_str.length());
		line.insert(pos, new_str);
		pos = line.find(old_str);
	}
	output << line << std::endl;
}

int	main(int argc, char *argv[]) {
	std::string		newFilename;
	std::string		line;
	std::ifstream 	file(argv[1]);

	if (checkArgs(argc, argv))
		return (1);
	newFilename = argv[1];
	newFilename += ".replace";
	if (file.is_open()) {
		std::ofstream	newfile(newFilename);
		if (!newfile.is_open()) {
			file.close();
			return (errorMessage("Can't open the output file", 1));
		}
		while (std::getline(file, line))
			replaceStr(line, newfile, argv[2], argv[3]);
		newfile.close();
	}
	else
		return (errorMessage("Can't open the input file", 1));
	file.close();
	return (0);
}