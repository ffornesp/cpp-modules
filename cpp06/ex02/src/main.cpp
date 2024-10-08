/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:56:49 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/08 12:25:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

Base	*generate( void ) {
	Base	*base;
	int		r;

	base = NULL;
	srand( time( NULL ) );
	r = rand()%3;
	switch ( r ) {
		case 0 :
			base = new A();
			std::cout << "Set to A\n";
			break ;
		case 1 :
			base = new B();
			std::cout << "Set to B\n";
			break ;
		case 2 :
			base = new C();
			std::cout << "Set to C\n";
			break ;
		default :
			break ;
	}
	return ( base );
}

void	identify( Base *p ) {	
	if ( dynamic_cast< A* >( p ) )
		std::cout << "Pointer identify: A" << std::endl;
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "Pointer identify: B" << std::endl;
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "Pointer identify: C" << std::endl;
	else
		std::cerr << "Pointer identify: Unknown type" << std::endl;
}

void	identify( Base& p ) {
	try {
		A &	a = dynamic_cast< A & > ( p );
		( void ) a;
		std::cout << "Reference identify: A" << std::endl;
	}
	catch ( std::exception &e ) {}
	try {
		B &	b = dynamic_cast< B & > ( p );
		( void ) b;
		std::cout << "Reference identify: B" << std::endl;
	}
	catch ( std::exception &e ) {}
	try {
		C &	c = dynamic_cast< C & > ( p );
		( void ) c;
		std::cout << "Reference identify: C" << std::endl;
	}
	catch ( std::exception &e ) {}
}

int	main( void ) {
	Base	*base;

	base = generate();
	identify( base );
	identify( *base );
	if ( base )
		delete base;
	return ( 0 );
}
