/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 16:04:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main( void ) {

// BUREAUCRAT creation tests

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

// BUREAUCRAT increment/decrement tests

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

	std::cout << "\nCreating a default ShrubberyCreationForm\n";
	ShrubberyCreationForm	s0;
	std::cout << s0 << std::endl;

	std::cout << "Creating a proper ShrubberyCreationForm\n";
	ShrubberyCreationForm	s1("Target_1");
	std::cout << s1 << std::endl;

	std::cout << "Creating a default RobotomyRequestForm\n";
	RobotomyRequestForm	r0;
	std::cout << r0 << std::endl;

	std::cout << "Creating a proper RobotomyRequestForm\n";
	RobotomyRequestForm	r1("Target_2");
	std::cout << r1 << std::endl;

	std::cout << "Creating a default PresidentialPardonForm\n";
	PresidentialPardonForm	p0;
	std::cout << p0 << std::endl;

	std::cout << "Creating a proper PresidentialPardonForm\n";
	PresidentialPardonForm	p1("Target_3");
	std::cout << p1 << std::endl;

// FORM sign ERROR - grade too low

	std::cout << "Attempting to sign the forms with a grade too low:\n\n";

	b3.signForm(s0);
	b3.signForm(s1);
	b3.signForm(r0);
	b3.signForm(r1);
	b3.signForm(p0);
	b3.signForm(p1);

	std::cout << std::endl;

// FORM execution ERROR - unsigned forms

	std::cout << "Attempting to execute the forms without signing\n\n";

	b2.executeForm(s0);
	b2.executeForm(s1);
	b2.executeForm(r0);
	b2.executeForm(r1);
	b2.executeForm(p0);
	b2.executeForm(p1);

	std::cout << std::endl;

// FORMS signed properly

	std::cout << "Attempting to sign the forms properly:\n\n";

	b2.signForm(s0);
	b2.signForm(s1);
	b2.signForm(r0);
	b2.signForm(r1);
	b2.signForm(p0);
	b2.signForm(p1);

	std::cout << std::endl;

// FORM sign ERROR - already signed

	std::cout << "Attempting to sign the forms already signed:\n\n";

	b2.signForm(s0);
	b2.signForm(s1);
	b2.signForm(r0);
	b2.signForm(r1);
	b2.signForm(p0);
	b2.signForm(p1);

	std::cout << std::endl;

// FORM execution tests

	std::cout << "Attempting to execute the forms with a grade too low:\n\n";

	b3.executeForm(s0);
	b3.executeForm(s1);
	b3.executeForm(r0);
	b3.executeForm(r1);
	b3.executeForm(p0);
	b3.executeForm(p1);

	std::cout << std::endl;

	std::cout << "Executing forms properly\n\n";

	b2.executeForm(s0);
	std::cout << std::endl;
	b2.executeForm(s1);
	std::cout << std::endl;
	b2.executeForm(r0);
	std::cout << std::endl;
	b2.executeForm(r1);
	std::cout << std::endl;
	b2.executeForm(p0);
	std::cout << std::endl;
	b2.executeForm(p1);

	std::cout << std::endl;
	
	return 0;
}
