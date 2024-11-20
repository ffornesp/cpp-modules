/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/20 12:38:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int argc, char *argv[] ) {
	if ( argc < 3 ) {
		std::cout << "Error: run program with a positive integer sequence as argument." << std::endl;
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

	std::cout << "After: ";
	printContent( src );

	// Implement the same for list
	return 0;
}
