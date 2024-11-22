/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:28:56 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/21 18:54:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <iostream>

static int	argError( std::string msg ) {
	std::cout << "Error: " << msg << std::endl;
	return 1;
}

int	main( int argc, char *argv[] ) {
	
	if ( argc < 2 )
		return argError( "Not enough arguments." );
	else if ( argc > 2 )
		return argError( "Too much arguments." );
	std::string	input = argv[ 1 ];
	std::string	str = removeSpaces( input );

	if ( !validateInput( str ) )
		return 1;

	RPN( str );
	return 0;
}
