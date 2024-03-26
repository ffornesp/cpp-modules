/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/26 14:09:48 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	b("Test_1", 149);
	Bureaucrat	n("Test_2", 2);
	Bureaucrat	f("Test_3", 0);
	Bureaucrat	d("Test_4", 151);

	std::cout << b << std::endl;
	b.decrement();
	std::cout << b << std::endl;
	b.decrement();
	std::cout << n << std::endl;
	n.increment();
	std::cout << n << std::endl;
	n.increment();
	std::cout << "FINAL:\n\t" << b << "\n\t" << n << "\n\t" << f << "\n\t" << d << std::endl;
	return 0;
}
