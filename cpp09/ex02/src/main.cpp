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
		std::cout << "Error: run program with a countitive integer sequence as argument." << std::endl;
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

//	Checks if main is full, if not:
//		Inserts the _second element in each ChainLink contained in myDeque sorted from small to big inside main
//		Also inserts those ChainLinks in the same order inside aux
//	Once main is full:
//		Inserts the _first element in each ChainLink contained in myDeque using jacobsthal numbers
static void	swap_insert( std::deque< int >& main, std::deque< ChainLink > chain[2] ) {
	if ( main.size() < chain[SRC].size() ) {
		static size_t	count = 0;

		if ( chain[SRC][count].compareElements() )
			chain[SRC][count].swapElements();
		if ( count++ < chain[SRC].size() - 1 )
			swap_insert( main, chain );
		else
			count--;

		std::deque< ChainLink >::iterator it = ChainLink_lower_bound( chain[AUX], chain[SRC][count] );
		chain[AUX].insert( it, chain[SRC][count] );

		int value = chain[SRC][count].getSecond();
		std::deque< int >::iterator ite = std::lower_bound( main.begin(), main.end(), value );
		main.insert( ite, value );
	
		count--;
		if ( main.size() < chain[SRC].size() )
			return ;
	}

	// At this point main and aux are filled with all the numbers

	printContent( main );
	printContent( chain[AUX] );

	// Implement jacobsthal insertion
}

void	sort( std::deque< ChainLink >& myDeque, std::list< ChainLink >& myList ) {
	std::deque< ChainLink > chain[2];
	std::deque< int >		mainChain;
	
	chain[ SRC ]  = myDeque;
	swap_insert( mainChain, chain );
	swap_insert( mainChain, chain );

//	printContent( mainChain );
//	printContent( chain[AUX] );
	( void )myList;
}
