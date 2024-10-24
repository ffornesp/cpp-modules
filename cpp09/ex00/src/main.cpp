/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:34:28 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 14:51:46 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int	main( int argc, char *argv[] ) {
	if ( argc != 1 )
		std::cerr << "Not enogh files provided" << std::endl;
	else if ( argc > 2 )
		std::cerr << "Please provide only one file" << std::endl;
	else {
		BitcoinExchange	btc;

		try {
			std::map< std::string, float > data = btc.readDatabase();
		}
		catch ( BitcoinExchange::InvalidReadException& e ) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
	}

	( void )argv;
	return 0;
}
