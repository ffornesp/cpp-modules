/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/11 15:13:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main( void ) {
	RobotomyRequestForm	r("Perro snaxe");
	Bureaucrat			b("Feijoo", 20);
	Bureaucrat			b1("Yoli", 40);

	r.beSigned(b1);
	r.execute(b);
	std::cout << std::endl << r << std::endl;
/*
	Bureaucrat	b("Pepito", 0);
	Bureaucrat	c("Cocoloco", 15);
	AForm f("Hola", 1, 1);

	std::cout << b << std::endl << f << std::endl;
	f.beSigned(c);
	f.beSigned(b);
	f.beSigned(c);
	std::cout << std::endl << b << std::endl << f;
*/
	return 0;
}
