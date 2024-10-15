/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/15 12:52:33 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void ) {
	std::cout << "Creating a bureaucrat using it's default constructor:\n";
	Bureaucrat	d;
	std::cout << "\n\t" << d << std::endl;

	std::cout << "\nCreating a bureaucrat with correct arguments:\n";
	Bureaucrat	c("Joseph", 42);
	std::cout << "\n\t" << c << std::endl;

	std::cout << "\nCreating a bureaucrat with a grade too high:\n";
	Bureaucrat	g1("Phillip", 0);
	std::cout << "\t" << g1 << std::endl;

	std::cout << "\nCreating a bureaucrat with a grade too low:\n";
	Bureaucrat	g2("Anuel", 151);
	std::cout << "\t" << g2 << std::endl;

	std::cout << "\nIncrementing the grade of a bureaucrat:\n";
	d.increment();
	std::cout << "\n\t" << d << std::endl;

	std::cout << "\nDecrementing the grade of a bureaucrat:\n";
	d.decrement();
	std::cout << "\n\t" << d << std::endl;

	std::cout << "\nIncrementing the grade of a bureaucrat but failing:\n";
	g1.increment();
	std::cout << "\t" << g1 << std::endl;

	std::cout << "\nDecrementing the grade of a bureaucrat but failing\n";
	g2.decrement();
	std::cout << "\t" << g2 << std::endl;
	return 0;
}
