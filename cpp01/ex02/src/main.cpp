/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 13:05:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[]) {
	
	std::string		salute = "HI THIS IS BRAIN";
	std::string*	stringPTR = &salute;
	std::string&	stringREF = salute;

	if (argc != 1)
		return (0);
	std::cout << "\tMEMORY ADDRESS" << std::endl;
	std::cout << "string:\t\t" << &salute << std::endl;
	std::cout << "pointer:\t" << stringPTR << std::endl;
	std::cout << "reference:\t" << &stringREF << std::endl;
	std::cout << std::endl << "\tVALUE" << std::endl;
	std::cout << "string:\t\t" << salute << std::endl;
	std::cout << "pointer:\t" << *stringPTR << std::endl;
	std::cout << "reference:\t" << stringREF << std::endl;
	(void)argv;
	return (0);
}