/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/14 19:25:29 by ffornes-         ###   ########.fr       */
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
	if ( argc < 3 ) {
		std::cout << "Error: run program with a countitive integer sequence as argument." << std::endl;
		return 1;
	}
	checkInput( argv + 1 );

	std::deque< int >	src;
	for ( int i = 1; argv[ i ] != NULL; i++ ) {
		src.push_back( atoi( argv[ i ] ) );
	}
	std::cout << "Before: ";
	printContent( src );

	mergeInsertionSort( src );

//	std::cout << "After: ";
//	printContent( myDeque );

	// Implement the same for list
	return 0;
}

static void	compareElements( std::deque< int >& src, size_t element_size ) {
	std::deque< int >::iterator	first = src.begin() + element_size - 1;
	std::deque< int >::iterator	second = src.begin() + ( element_size * 2 ) - 1;
	size_t						count = ( element_size * 2 ) - 1;

	while ( count <= src.size() ) {
		std::cout << "Comparing:\t[" << *first << "][" << *second << "]" << std::endl;

		if ( *first > *second ) {
			std::cout << "[" << *( first - element_size + 1 ) << "][" << *(first + 1) << "]" << std::endl;
			std::swap_ranges( first - element_size + 1, first + 1, second);
		}

		count += element_size;
		first = src.begin() + count;

		count += element_size;
		second = src.begin() + count;

		std::cout << "Current chain:\t";
		printContent( src );
	}
}

static void	updateValues( size_t& element_size, size_t& size, bool flag ) {
	if ( flag == INCREMENT ) {
		element_size *= 2;
		size /= 2;
	} else {
		element_size /= 2;
		size *= 2;
	}
}

void	mergeInsertionSort( std::deque< int >& src ) {
	static size_t	element_size = 1;
	static size_t	size = src.size();

	// DEBUG
	static size_t	count = 0;
	std::cout << "\nEntered mergeInsertionSort: " << ++count << " times" << std::endl;
	std::cout << "\tElement_size: " << element_size << std::endl;
	std::cout << "\tSize: " << size << std::endl;
	// ENDEBUG

	if ( size > 1 ) {
		compareElements( src, element_size );
//		printContent( src );
		updateValues( element_size, size, INCREMENT );
		mergeInsertionSort( src );
	}

	// DEBUG
//	std::cout << "Element_size: " << element_size << std::endl;
//	std::cout << "Size: " << size << std::endl << std::endl;
	// ENDEBUG

	if ( element_size > 1 ) {
		// Create main chain using src as reference
		// Create a main_chain to store the biggest element in each group of pairs using
		//		element_size
		updateValues( element_size, size, DECREMENT );
		return ;
	}

	return ;
}







	// TODO		GET RID OF CHAINLINKS LMAOOOOXDDXDXD and implement everything with deque<int>
	//	maybe>? use iterators? why? theres std::swap range that makes it easier to swap elements




/*
		WHAT TO DO?

	call merge-insertion-sort
		element_size = 1
		size = 9

	5 2 3 1 4 7 6 9 8 

	swap content inside pairs

	[5-2] [3-1] [4-7] [6-9] | 8				
	[2-5] [1-3] [4-7] [6-9] | 8

	call merge-insertion-sort
		element_size = 2
		size = 4

	swap content inside pairs

	[(2-5) (1-3)] [(4-7) (6-9)]
	[(1-3)-(2-5)] [(4-7)-(6-9)]

	call merge-insertion-sort
		element_size = 4
		size = 2

	swap content inside pairs

	[((1-3)-(2-5)) ((4-7)-(6-9))] 		since 5 < 9 we do not swap content
	[((1-3)-(2-5))-((4-7)-(6-9))] 

	call merge-insertion-sort
		element_size = 8
		size = 1 ; then return

	
	call jacobsthal haha xdxd

	when calling jacobsthal we will keep the reference of the paired number using an iterator
	the main difference between deque and list is that list will be able to keep it's iterator
	intact event tho we insert stuff in between, however that's not the case for deque

*/
