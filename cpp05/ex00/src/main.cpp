/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:01:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/25 17:24:31 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	b("Ferran", 149);
	Bureaucrat	n("Nadia", 2);

	std::cout << b << std::endl;
	b.increment();
	std::cout << b << std::endl;
	b.increment();
	std::cout << n << std::endl;
	n.decrement();
	std::cout << n << std::endl;
	n.decrement();
	return 0;
}
