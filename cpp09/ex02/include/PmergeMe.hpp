/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/31 17:27:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <deque>
#include <cstdlib>
#include <iostream>

void	sort( std::deque< int > deq, std::list< int > list );

template< typename T >
void	fillContainer( T& t, char *argv[] ) {
	for ( int i = 1; argv[ i ] != NULL; i++ )
		t.push_back( atoi( argv[ i ] ) );
}

template< typename T >
void	printContent( T& t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}

template< typename T >
void	sortPairs( T& t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ ) {
		typename T::iterator previous = it;
		it++;
		if ( it == t.end() )
			return ;
		else if ( *previous > *it )
			std::swap( *it, *previous );
	}
}
