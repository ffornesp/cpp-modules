/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/18 14:29:50 by ffornes-         ###   ########.fr       */
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

static void	fillChain( std::deque< int >& dst, std::deque< int > src, size_t element_size, size_t& groups ) {
	std::deque< int >::iterator pos = src.begin() + element_size;
	for ( size_t count = groups * 0.5f; count > 0; count-- ) {
		dst.insert( dst.end(), pos, pos + element_size );
		pos += element_size * 2;
		groups--;
	}
}

// TODO this....
static std::deque< int >::iterator( std::deque< int > chain, size_t element_size, int value ) {
	std::deque< int >::iterator	it = chain.begin();

	// This is so wrong/
	std::cout << "Looking for: " << value << std::endl;
	(void)element_size;

	return it;
}

// TODO make it workworkworkworkwork
static void	binarySearchInsertion( std::deque< int >& src, size_t element_size ) {
	std::deque< int >	mainChain;
	size_t	groups = src.size() / element_size;
	
	fillChain( mainChain, src, element_size, groups );

	// Remove this
	std::cout << std::endl;

	size_t	n = 0;
	size_t	jacob = 0;
	while ( 42 ) {
		if ( jacobsthalNumbers[ n ] == 0 )
			mainChain.insert( mainChain.begin(), src.begin(), src.begin() + element_size );
		else {
			jacob += jacobsthalNumbers[ n ] + 1;
			std::deque< int >::iterator first = src.begin() + element_size * jacob;
			std::deque< int >::iterator	second = first + element_size;
			// Look for the iterator where I need to insert everything using binary search
			std::cout << "Group defined by: [" << *first << " " << *second << "]" << std::endl;

			std::deque< int >::iterator	pos = binarySearch( mainChain, element_size, *( second - 1 ) );
			std::cout << "Position found: " << *it << std::endl;
			// Write function that returns iterator to the position of the group I want
			// to insert, passing it the index of the group and src.
			break ;
		}
		std::cout << "Jacob: " << jacobsthalNumbers[n] << " Index: " << n << std::endl;

		groups--;
		n++;
	
		std::cout << "Original:\t";
		printGroups( src, element_size );
		std::cout << "Main chain:\t";
		printGroups( mainChain, element_size );
		std::cout << std::endl;
	}
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
