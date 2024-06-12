/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/06/12 12:55:46 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main( void ) {
	Bureaucrat	c("Cocoloco", 15);
	Form f1("Hola", 15, 15);
	Form f2("TOO LOW", 1, 1);
	Form f3("Already signed", 15, 15);
	std::cout << c << std::endl << f1 << "\n\n" << f2 << "\n\n" << f3 << "\n";
	c.signForm(f1);
	c.signForm(f2);
	c.signForm(f3);
	c.signForm(f3);
	std::cout << std::endl << f1 << "\n\n" << f2 << "\n\n" << f3 << "\n";
	return 0;
}
