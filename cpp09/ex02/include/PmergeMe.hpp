/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/31 13:27:55 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <deque>
#include <cstdlib>
#include <iostream>

template< typename T >
void	fillContainer( T& t, char *argv[] ) {
	for ( int i = 1; argv[ i ] != NULL; i++ )
		t.push_back( atoi( argv[ i ] ) );
}

/*	CHECK CONTENT OF DEQUE OR LIST CONTAINER

template< typename T >
void	check( T& t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ ) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}
*/
