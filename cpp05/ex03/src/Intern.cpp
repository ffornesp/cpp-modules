/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:48:21 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 17:21:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

Intern::Intern( void ) {}

Intern::~Intern( void ) {}

Intern::Intern( const Intern& old ) {
	*this = old;
}

Intern& Intern::operator=( const Intern& ) {
	return (*this);	
}

AForm* Intern::makeForm( std::string name, std::string target ) {
	AForm*		out;
	std::string	forms[3];
	size_t		iterator;

	forms[0] = "Presidential pardon";
	forms[1] = "Robotomy request";
	forms[2] = "Shrubbery creation";
	iterator = 0;
	while ( iterator < 3 ) {
		if ( forms[iterator] == name )
			break ;
		iterator++;
	}
	switch	(iterator) {
		default :
			out = NULL;
			break ;
		case PRESIDENTIAL_PARDON :
			out = new PresidentialPardonForm(target);
			break ;
		case ROBOTOMY_REQUEST :
			out = new RobotomyRequestForm(target);
			break ;
		case SHRUBBERY_CREATION :
			out = new ShrubberyCreationForm(target);
			break ;
	}
	if ( out )
		std::cout << "Intern creates " << out->getName() << std::endl << *out << std::endl;
	else {
		std::cerr << RED << name << " is not a valid form name, please input one of the following:\n" << RESET;
		std::cerr << RED << "\tPresidential pardon\n\tRobotomy request\n\tShrubbery creation" << RESET << std::endl;
	}
	return ( out );
}
