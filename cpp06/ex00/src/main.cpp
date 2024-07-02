/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:31:47 by ffornes-          #+#    #+#             */
/*   Updated: 2024/07/02 12:43:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main( int argc, char *argv[] ) {
	if ( argc != 2 )
		std::cerr << "Please run program with just one string" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return ( 0 );
}
