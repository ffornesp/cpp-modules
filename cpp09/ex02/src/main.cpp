/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/21 16:36:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

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

	clock_t	start;
	clock_t	end;

	std::cout << "Before:\t";
	printContent( myDeque );

	start = std::clock();
	mergeInsertionSort( myDeque );
	end = std::clock();

	double	dequeTime = static_cast< double >( end - start ) * 1000000 / CLOCKS_PER_SEC;
	
	start = std::clock();
	mergeInsertionSort( myList );
	end = std::clock();

	double	listTime = static_cast< double >( end - start ) * 1000000 / CLOCKS_PER_SEC;

	std::cout << "After:\t";
	printContent( myDeque );
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[deque] : " << dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[list] : " << listTime << " us" << std::endl;

	return 0;
}
