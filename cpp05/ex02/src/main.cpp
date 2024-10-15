/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 12:59:56 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main( void ) {
	std::cout << "Creating a bureaucrat using it's default constructor:\n";
	Bureaucrat	b0;
	std::cout << "\n\t" << b0 << std::endl;

	std::cout << "\nCreating a bureaucrat with correct arguments:\n";
	Bureaucrat	b1("Joseph", 42);
	std::cout << "\n\t" << b1 << std::endl;

	std::cout << "\nCreating a bureaucrat with a grade too high:\n";
	Bureaucrat	b2("Phillip", 0);
	std::cout << "\t" << b2 << std::endl;

	std::cout << "\nCreating a bureaucrat with a grade too low:\n";
	Bureaucrat	b3("Anuel", 151);
	std::cout << "\t" << b3 << std::endl;

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

	std::cout << "\nCreating a form using it's default constructor:\n\n";
	AForm		f0;
	std::cout << f0 << std::endl;
	
	std::cout << "Creating a form with correct arguments:\n\n";
	AForm		f1("TIG Form", 21, 42);
	std::cout << f1 << std::endl;

	// If the creation throws an exception is catched by the constructor itself
	//which prevents the main from catching the exception thus the form is created
	//anyway with the wrong parameters.
	std::cout << "Creating a form with a grade too high:\n";
	AForm		f2("1to1 Form", 0, 151);
	std::cout << f2 << std::endl;

	std::cout << "Signing first form:\n";
	b0.signForm(f0);
	std::cout << f0 << std::endl;

	std::cout << "Attempting to sign a form but failing because of the grade:\n";
	b0.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "Attempting to sign a form but failing because it's already signed\n";
	b0.signForm(f0);
	std::cout << f0 << std::endl;

	std::cout << "Creating a default ShrubberyCreationForm\n";
	ShrubberyCreationForm	s0;
	std::cout << s0 << std::endl;

	std::cout << "Creating a proper ShrubberyCreationForm\n";
	ShrubberyCreationForm	s1("ShrubberyCreationForm");
	std::cout << s1 << std::endl;

	std::cout << "Creating a default RobotomyRequestForm\n";
	RobotomyRequestForm	r0;
	std::cout << r0 << std::endl;

	std::cout << "Creating a proper RobotomyRequestForm\n";
	RobotomyRequestForm	r1("RobotomyRequestForm");
	std::cout << r1 << std::endl;

	std::cout << "Creating a default PresidentialPardonForm\n";
	PresidentialPardonForm	p0;
	std::cout << p0 << std::endl;

	std::cout << "Creating a proper PresidentialPardonForm\n";
	PresidentialPardonForm	p1("PresidentialPardonForm");
	std::cout << p1 << std::endl;

	// Test execution of forms
	std::cout << "Executing ShrubberyCreationForm:\n";
	b1.executeForm(s1);
	return 0;
}
