/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/18 13:00:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>

static void	updateValues( size_t& element_size, size_t& size, bool flag );

const int	jacobsthalNumbers[15] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461 };

int	main( int argc, char *argv[] ) {
	if ( argc < 3 ) {
		std::cout << "Error: run program with a pos0itive integer sequence as argument." << std::endl;
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
	size_t	tail = element_size - 1;

	while ( tail + element_size < src.size() ) {
		std::deque< int >::iterator	first = src.begin() + tail;
		std::deque< int >::iterator	second = src.begin() + tail + element_size;
		if ( *first > *second )
			std::swap_ranges( first - element_size + 1, first + 1, second - element_size + 1);
		tail += element_size * 2;
	}
}

// TODO make it workworkworkworkwork
static void	binarySearchInsertion( std::deque< int >& src, size_t element_size ) {
	std::deque< int >	mainChain;
	size_t				n = 0;

	size_t	groups = src.size() / element_size;
	std::cout << "Found " << groups << " groups of numbers" << std::endl;

	for ( std::deque< int >::iterator it = src.begin(); it != src.end(); it++ ) {
		if ( n++ >= element_size ) {
			mainChain.push_back( *it );
			if ( n >=  element_size * 2 ) {
				groups--;
				n = 0;
			}
		}
	}
// DEBUG
	std::cout << "Original:\t";
	printGroups( src, element_size );
	std::cout << "Main chain:\t";
	printGroups( mainChain, element_size );
	std::cout << "Found " << groups << " groups of numbers" << std::endl;
// ENDEBUG
	n = 0;
	while ( groups ) {
		switch ( jacobsthalNumbers[ n ] ) {
			case 0:
//				for ( std::deque< int >::iterator it = src.begin(); it != src.end(); it++ ) {
						
//				}
				break ;
			default:
				// Advance until you find first iterator of group
				// 
				// DEBUG
				std::cout << "Case: " << jacobsthalNumbers[ n ] << " " << n << std::endl;
				// ENDEBUG
		}
		n++;
		if ( n > src.size() / element_size )
			break ;
	}
// DEBUG
	printGroups( mainChain, element_size );
// ENDEBUG
}

void	mergeInsertionSort( std::deque< int >& src ) {
	static size_t	element_size = 1;
	static size_t	size = src.size();

	if ( size > 1 ) {
		compareElements( src, element_size );
		updateValues( element_size, size, INCREMENT );
		mergeInsertionSort( src );
	}
	if ( element_size > 1 ) {
		// Apply binary search insertion to current pair group using jacobsthal sequence
		//	Only applies to cases that size is >= 4 since you can't apply merge insertion
		//	with jacobsthal numbers to size 1 and in the case of size 2 the groups are
		//	already sorted.
		if ( size >= 4 )
			binarySearchInsertion( src, element_size );
		// Update values for next iteration & return
		updateValues( element_size, size, DECREMENT );
		return ;
	}

	return ;
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
