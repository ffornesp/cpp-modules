/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 16:47:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main( void ) {

// BUREAUCRAT creation tests
	std::cout << std::endl;
	std::cout << YELLOW << "\tBureaucrat creation tests:\n" << RESET << std::endl;

	std::cout << "Creating a bureaucrat using it's default constructor:\n";
	Bureaucrat	b0;
	std::cout << "\n\t" << b0 << std::endl;

	std::cout << "\nCreating a bureaucrat with correct arguments:\n";
	Bureaucrat	b1("Joseph", 42);
	std::cout << "\n\t" << b1 << std::endl;
	// BUREAUCRAT creation ERRORS
	std::cout << "\nCreating a bureaucrat with a grade too high:\n";
	Bureaucrat	b2("Phillip", 0);
	std::cout << "\t" << b2 << std::endl;

	std::cout << "\nCreating a bureaucrat with a grade too low:\n";
	Bureaucrat	b3("Anuel", 151);
	std::cout << "\t" << b3 << std::endl;

// BUREAUCRAT increment/decrement tests
	std::cout << std::endl;
	std::cout << YELLOW << "\tBureaucrat increment/decrement tests:" << RESET << std::endl;

	std::cout << "\nIncrementing the grade of a bureaucrat:\n";
	b1.increment();
	std::cout << "\n\t" << b0 << std::endl;

	std::cout << "\nDecrementing the grade of a bureaucrat:\n";
	b1.decrement();
	std::cout << "\n\t" << b0 << std::endl;

	std::cout << "\nIncrementing the grade of a bureaucrat but failing:\n";
	b2.increment();
	std::cout << "\t" << b2 << std::endl;

	std::cout << "\nDecrementing the grade of a bureaucrat but failing\n";
	b3.decrement();
	std::cout << "\t" << b3 << std::endl;

// FORM creation tests
	std::cout << std::endl;
	std::cout << YELLOW << "\tForm creation tests:\n" << RESET << std::endl;
	std::cout << "Creating a form using it's default constructor:\n" << std::endl;
	Form		f0;
	std::cout << f0 << std::endl;
	
	std::cout << "Creating a form with correct arguments:\n\n";
	Form		f1("TIG Form", 21, 42);
	std::cout << f1 << std::endl;
	// FORM creation ERRORS
	std::cout << "Creating a form with a sign grade too high:\n";
	try {
		Form		f2( "1to1 Form", 0, 150 );
		std::cout << f2 << std::endl;
	}
	catch ( Form::GradeTooHighException& e ) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Creating a form with a sign grade too low:\n";
	try {
		Form	f3( "1to1 Form", 151, 1 );
		std::cout  << f3 << std::endl;
	}
	catch ( Form::GradeTooLowException& e ) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Creating a form with a execution grade too high:\n";
	try {
		Form		f4( "1to1 Form", 1, 0 );
		std::cout << f4 << std::endl;
	}
	catch ( Form::GradeTooHighException& e ) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "Creating a form with a execution grade too low:\n";
	try {
		Form	f5( "1to1 Form", 1, 151 );
		std::cout  << f5 << std::endl;
	}
	catch ( Form::GradeTooLowException& e ) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

// FORM sign tests
	std::cout << YELLOW << "\tForm sign tests:\n" << RESET << std::endl;
	std::cout << "Signing first form:\n";
	b0.signForm(f0);
	std::cout << f0 << std::endl;
	// FORM sign ERRORS
	std::cout << "Attempting to sign a form but failing because of the grade:\n";
	b0.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "Attempting to sign a form but failing because it's already signed\n";
	b0.signForm(f0);
	std::cout << f0 << std::endl;
	return 0;
}
