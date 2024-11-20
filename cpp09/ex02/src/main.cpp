/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/20 17:58:00 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int argc, char *argv[] ) {
	if ( argc < 3 ) {
		std::cout << "Error: run program with a positive integer sequence as argument." << std::endl;
		return 1;
	}
	checkInput( argv + 1 );

	std::deque< int >	myDeque;
	std::list< int >	myList;
	for ( int i = 1; argv[ i ] != NULL; i++ ) {
		int	n = atoi( argv[ i ] );
		myDeque.push_back( n );
		myList.push_back( n );
	}
	std::cout << "Before: ";
	printContent( myDeque );

	mergeInsertionSort( myDeque );

	std::cout << "After: ";
	printContent( myDeque );

	std::cout << "\nBefore: ";
	printContent( myList );

	mergeInsertionSort( myList );

	std::cout << "After: ";
	printContent( myList );

	return 0;
}
