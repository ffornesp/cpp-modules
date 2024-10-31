/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/31 13:40:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

static void badInput( void ) {
	std::cout << "Error: invalid input." << std::endl;
	exit( 1 );
}

static void	checkInput( char *str ) {
	int		i = 0;
	long	l = atol( str );

	if ( l < 0 || l > INT_MAX )
		badInput();
	while ( str[ i ] )
		if ( !isdigit( str[ i++ ] ) )
			badInput();
}

int	main( int argc, char *argv[] ) {
	if ( argc < 2 )
		std::cout << "Error: run program with a positive integer sequence as argument." << std::endl;
	else {
		for ( int i = 1; i < argc; i++ )
			checkInput( argv[i]);
		std::cout << "Before:\t";
		for ( int i = 1; i < argc; i++ )
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		std::deque< int  >	caseDeque;
		std::list< int >	caseList;
		fillContainer( caseDeque, argv );
		fillContainer( caseList, argv );
		// here
	}
	return 0;
}
