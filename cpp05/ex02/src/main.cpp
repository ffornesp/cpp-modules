/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/10 17:28:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main( void ) {
	Bureaucrat	b("Pepito", 0);
	Bureaucrat	c("Cocoloco", 15);
	AForm f("Hola", 1, 1);

	std::cout << b << std::endl << f << std::endl;
	f.beSigned(c);
	f.beSigned(b);
	f.beSigned(c);
	std::cout << std::endl << b << std::endl << f;
	return 0;
}
