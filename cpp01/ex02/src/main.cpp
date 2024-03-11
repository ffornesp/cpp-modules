/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:42 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 17:11:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	
	std::string		salute = "HI THIS IS BRAIN";
	std::string*	stringPTR = &salute;
	std::string&	stringREF = salute;

	std::cout << "\tMEMORY ADDRESS" << std::endl;
	std::cout << "string:\t\t" << &salute << std::endl;
	std::cout << "pointer:\t" << stringPTR << std::endl;
	std::cout << "reference:\t" << &stringREF << std::endl;
	std::cout << std::endl << "\tVALUE" << std::endl;
	std::cout << "string:\t\t" << salute << std::endl;
	std::cout << "pointer:\t" << *stringPTR << std::endl;
	std::cout << "reference:\t" << stringREF << std::endl;
	return (0);
}
