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

static void	updateValues( size_t& element_size, size_t& size, bool flag );

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
		std::cout << "Elements compared: " << tail - element_size + 1 << std::endl;
		std::deque< int >::iterator	first = src.begin() + tail;
		std::deque< int >::iterator	second = src.begin() + tail + element_size;

		std::cout << "Comparing:\t[" << *first << "][" << *second << "]" << std::endl;
		std::cout << "Chain b4 comparison:\t";
		printGroups( src, element_size );
		if ( *first > *second )
			std::swap_ranges( first - element_size + 1, first + 1, second - element_size + 1);

		tail += element_size * 2;

		std::cout << "Chain after comparison:\t";
		printGroups( src, element_size );
		std::cout << std::endl;
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

static void	updateValues( size_t& element_size, size_t& size, bool flag ) {
	if ( flag == INCREMENT ) {
		element_size *= 2;
		size /= 2;
	} else {
		element_size /= 2;
		size *= 2;
	}
}
