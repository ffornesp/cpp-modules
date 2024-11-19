/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/19 18:49:12 by ffornes-         ###   ########.fr       */
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

static void	printInfo( std::deque< int > src, std::deque< int > mainChain, size_t element_size ) {
	std::cout << std::endl << "Main chain:\t";
	printGroups( mainChain, element_size );
	std::cout << "Original:\t";
	printGroups( src, element_size );
	std::cout << std::endl;
}

static size_t	binarySearch( std::deque< int > src, size_t element_size, int value, int limitValue ) {
	size_t	low = element_size - 1;
	size_t	high = 0;
	size_t	count = 0;

	if ( limitValue > 0 ) {
		// Search using functions of deque?
		for ( size_t i = element_size - 1; i < src.size(); i += element_size ) {
			if ( src[ i ] == limitValue )
				high = i - element_size;
		}
	}
	else
		high = src.size() - 1;

	while ( low < high ) {
		size_t	mid = ( high - low ) / ( 2 * element_size ) * element_size + low;
		count++;
		if ( value < src[ mid ] )
			high = mid;
		else {
			low = mid + element_size;
			if ( low == high && value > src[ low ] ) {
				count++;
				std::cout << "COUNT : " << count << std::endl;
				return low + 1;
			}
		}
	}
	std::cout << "COUNT : " << count << std::endl;
	return low - element_size + 1;
}

static void	binarySearchInsertion( std::deque< int >& src, size_t element_size ) {
	std::deque< int >	mainChain;
	size_t	groups = src.size() / element_size;
	size_t	odd = 0;
	
	if ( groups & 1 ) {
		std::cout << "Groups are odd, we must insert last element at the end" << std::endl;
		odd = groups;
		groups--;
	}

	fillChain( mainChain, src, element_size, groups );
	printInfo( src, mainChain, element_size );
	
	size_t	n = 0;
	int		jacob = jacobsthalNumbers[ n ] * 2;
	int		previousJacob = 0;
	while ( groups ) {
		if ( jacob == 0 ) {
			mainChain.insert( mainChain.begin(), src.begin(), src.begin() + element_size );
			groups--;
			printInfo( src, mainChain, element_size );
		}
		while ( jacob > previousJacob ) {
			std::cout << "JACOB: " << jacob << " PREVIOUS: " << previousJacob << std::endl;
			std::cout << "Trying to insert: " << element_size * jacob * 2 << std::endl;
			if ( ( element_size * jacob * 2 + element_size ) < src.size() ) {
				std::deque< int >::iterator	first = src.begin() + element_size * jacob * 2;
				std::deque< int >::iterator	second = first + element_size;
				std::deque< int >::iterator	pos = mainChain.begin() + binarySearch( mainChain, element_size, *( second - 1 ), src[( element_size * jacob * 2 ) + element_size - 1 + element_size] );
				mainChain.insert( pos, first, second );
				groups--;

				printInfo( src, mainChain, element_size );
			}
			jacob--;
		}
		if ( groups ) {
			previousJacob += jacobsthalNumbers[ n++ ] * 2;
			jacob = previousJacob + jacobsthalNumbers[ n ] * 2;
		}
	}
	//	Inserts the last group in case that the group doesn't have a pair aka it's leftover
	if ( odd > 0 ) {
		std::deque< int >::iterator	first = src.begin() + element_size * ( odd - 1 );
		std::deque< int >::iterator	second = first + element_size;
		std::deque< int >::iterator	pos = mainChain.begin() + binarySearch( mainChain, element_size, *( second - 1 ), *( second - 1 + element_size ) );
		mainChain.insert( pos, first, second );
	}
	src = mainChain;
	std::cout << YELLOW << "FINISH\t\t" << DEFAULT;
	printGroups( mainChain, element_size );
}

void	mergeInsertionSort( std::deque< int >& src ) {
	static size_t	element_size = 1;
	static size_t	size = src.size();

	if ( size > 1 ) {
		compareElements( src, element_size );
		updateValues( element_size, size, INCREMENT );
		mergeInsertionSort( src );
	}
		if ( size >= 4 )
			binarySearchInsertion( src, element_size );
		updateValues( element_size, size, DECREMENT );
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
