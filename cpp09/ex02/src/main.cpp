/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/05 18:41:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>

static void badInput( std::string msg ) {
	std::cout << "Error: invalid input" << msg << std::endl;
	exit( 1 );
}

static void	checkInput( char *argv[] ) {
	long				l;
	std::list< int >	myList;

	for ( int i = 0; argv[i] != NULL; i++ ) {
		l = atol( argv[i] );
		if ( l < 0 )
			badInput( ", there can't be any negative numbers." );
		else if ( l > INT_MAX )
			badInput( ", out of integer range." );
		for ( int j = 0; argv[i][j] != '\0'; j++ )
			if ( !isdigit( argv[i][j] ) )
				badInput( ", non digit characters found." );
		for ( std::list< int >::iterator it = myList.begin(); it != myList.end(); it++ )
			if ( static_cast< int >( l ) == *it )
				badInput( ", duplicates found." );
		myList.push_back( static_cast< int >( l ) );
	}
}

int	main( int argc, char *argv[] ) {
	std::deque< ChainLink >	myDeque;
	std::list< ChainLink >	myList;

	if ( argc < 3 )
		std::cout << "Error: run program with a positive integer sequence as argument." << std::endl;
	else {
		checkInput( argv + 1 );
		
		fillContainer( myDeque, argv );
		fillContainer( myList, argv );

		std::cout << "Before: ";
		printContent( myDeque );

		sort( myDeque, myList );

		std::cout << "After: ";
		printContent( myDeque );
	}
	return 0;
}

void	sort( std::deque< ChainLink >& myDeque, std::list< ChainLink >& myList ) {

	sortInside( myDeque );
	// DEBUG
	std::cout << "After sort elements: ";
	printContent( myDeque );
	// ENDEBUG

	// Once the content inside the chainlinks is sorted, we must sort the pairs
	//	based only on their _first ( main chain ). We use binary insertion.

	// After we have the "main chain" sorted, we have to send the first numbers
	//	into a new deque that will contain the final result for the sorted numbers.

	// Once we have pushed all the _first elements into the new deque, we have to
	//	insert the _second elements using jacobsthal numbers and binary insertion

	// DEBUG
//	sortPairs( myList );
	(void)myList;
	// ENDEBUG
}
