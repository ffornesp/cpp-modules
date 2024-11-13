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

// Remember to handle the last element in case there's no pair at the end

		fillContainer( myDeque, argv );
		fillContainer( myList, argv );

//		std::cout << "Before: ";
//		printContent( myDeque );

		sort( myDeque, myList );

//		std::cout << "After: ";
//		printContent( myDeque );
	}
	return 0;
}

//	This function calls itself until the 'out' deque is filled with all the elements from 'myDeque' sorted by
// each ChainLink _second element.
static void	swap_insert( std::deque< ChainLink >& out, std::deque< ChainLink >& myDeque, int pos, int endPos ) { 
	if ( pos > endPos )
		return ;

	if ( myDeque[pos].compareElements() )
		myDeque[pos].swapElements();

	if ( pos == endPos ) {
		std::deque< ChainLink >::iterator it = ChainLink_lower_bound( out, myDeque[pos] );
		out.insert( it, myDeque[pos] );
		return ;
	}
	
	swap_insert( out, myDeque, pos + 1, endPos );

	std::deque< ChainLink >::iterator it = ChainLink_lower_bound( out, myDeque[pos] );
	out.insert( it, myDeque[pos] );
}

void	sort( std::deque< ChainLink >& myDeque, std::list< ChainLink >& myList ) {
	std::deque< ChainLink >	newChain;

	swap_insert( newChain, myDeque, 0, myDeque.size() - 1 );
	// Insert _first elements with jacobsthal numbers

	printContent( newChain );

	( void )myList;
}
