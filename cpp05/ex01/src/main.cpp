/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/10 18:24:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	std::cout << "\nCreating a form using it's default constructor:\n\n";
	Form		f0;
	std::cout << f0 << std::endl;
	
	std::cout << "Creating a form with correct arguments:\n\n";
	Form		f1("TIG Form", 21, 42);
	std::cout << f1 << std::endl;

	std::cout << "Creating a form with a grade too high:\n";
	Form		f2("1to1 Form", 0, 151);
	std::cout << f2 << std::endl;

	return 0;
}
