/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 17:36:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main( void ) {
	Intern	i;
	AForm*	form;
	AForm*	presidentialForm;
	AForm*	shrubberyForm;
	AForm*	robotomyForm;

	form = i.makeForm( "TIG form", "Oktorok" );
	if ( form ) {
		delete form;
	}
	presidentialForm = i.makeForm( "Presidential pardon", "Obama" );
	shrubberyForm =  i.makeForm( "Shrubbery creation", "file" );
	robotomyForm = i.makeForm( "Robotomy request", "Bender" );

	Bureaucrat	b0( "Pedrito", 1 );
	b0.signForm( *presidentialForm );
	b0.signForm( *shrubberyForm );
	b0.signForm( *robotomyForm );
	
	std::cout << std::endl;
	std::cout << *presidentialForm << std::endl;
	std::cout << *shrubberyForm << std::endl;
	std::cout << *robotomyForm << std::endl;

	b0.executeForm( *presidentialForm );
	b0.executeForm( *shrubberyForm );
	b0.executeForm( *robotomyForm );

	if ( presidentialForm )
		delete presidentialForm;
	if ( shrubberyForm )
		delete shrubberyForm;
	if ( robotomyForm )
		delete robotomyForm;
}
