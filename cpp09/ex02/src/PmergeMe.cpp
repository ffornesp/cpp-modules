/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:11 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/20 12:30:33 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <list>

static void	updateValues( size_t& element_size, size_t& size, bool flag );
static void	sortPairs( std::deque< int >& src, size_t element_size );

void	mergeInsertionSort( std::deque< int >& src ) {
	static size_t	element_size = 1;
	static size_t	size = src.size();

	if ( size > 1 ) {
		sortPairs( src, element_size );
		updateValues( element_size, size, INCREMENT );
		mergeInsertionSort( src );
	}
	if ( size >= 4 )
		binarySearchInsertion( src, element_size );
	updateValues( element_size, size, DECREMENT );
	return ;
}

static void	sortPairs( std::deque< int >& src, size_t element_size ) {
	size_t	tail = element_size - 1;
	size_t	count = 0;
	while ( tail + element_size < src.size() ) {
		std::deque< int >::iterator	first = src.begin() + tail;
		std::deque< int >::iterator	second = src.begin() + tail + element_size;
		count++;
		if ( *first > *second ) {
			std::swap_ranges( first - element_size + 1, first + 1, second - element_size + 1);
		}
		tail += element_size * 2;
	}
	std::cout << "COUNT IN PAIRS: " << count << std::endl;
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
