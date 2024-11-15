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
