/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:49:48 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 18:00:37 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>

int	main( void ) {
	Span	s( 10000 );
	
	for ( int i = 0; i < 10000; i++ ) {
		s.addNumber( i * 2 );
	}
	std::cout << std::endl << "\t\tREGULAR TESTS" << std::endl;
	std::cout << std::endl;
	std::cout << "Shortest span : " << s.shortestSpan() << std::endl;
	std::cout << "Longest span : " << s.longestSpan() << std::endl;
	std::cout << std::endl;

// SUBJECT TEST
	std::cout << "\tSubject test:" << std::endl;
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

// EXCEPTIONS
	std::cout << std::endl << "\t\tEXCEPTION HANDLING" << std::endl;
	std::cout << std::endl;
	std::cout << "\tTrying to add a number to a maxed out span:" << std::endl;
	try {
		s.addNumber( 255 );
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
// Shortest span tests with empty or size1 spans
	std::cout << "\tTrying to find shortest span of an empty span:" << std::endl;
	try {
		Span	s1;

		s1.shortestSpan();
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\tTrying to find shortest span of an span with size 1:" << std::endl;
	try {
		Span	s1( 1 );
	
		s1.addNumber( 1 );
		s1.shortestSpan();
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
// Longest span tests with empty or size1 spans
	std::cout << "\tTrying to find longest span of an empty span:" << std::endl;
	try {
		Span	s1;

		s1.longestSpan();
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\tTrying to find longest span of an span with size 1:" << std::endl;
	try {
		Span	s1( 1 );
	
		s1.addNumber( 1 );
		s1.longestSpan();
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
