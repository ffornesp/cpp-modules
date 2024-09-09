/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:56:49 by ffornes-          #+#    #+#             */
/*   Updated: 2024/09/09 16:37:52 by ffornes-         ###   ########.fr       */
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
			break ;
		case 1 :
			base = new B();
			break ;
		case 2 :
			base = new C();
			break ;
		default :
			break ;
	}
	return ( base );
}

/*
void	identify( Base *p ) {
	
}

void	identify( Base& p ) {
	
}
*/

int	main( void ) {
	Base	*base;

	base = generate();
	if ( base )
		delete base;
//	identify( base );
//	identify( *base );
	return ( 0 );
}
