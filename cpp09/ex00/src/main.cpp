/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:34:28 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/24 15:47:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int	main( int argc, char *argv[] ) {
	if ( argc < 2 )
		std::cerr << "Not enogh files provided" << std::endl;
	else if ( argc > 2 )
		std::cerr << "Please provide only one file" << std::endl;
	else {
		BitcoinExchange	btc;

		btc.btc( argv[1] );
	}
	return 0;
}
