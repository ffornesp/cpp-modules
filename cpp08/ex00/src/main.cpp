/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:49:48 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 15:36:43 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int	main( void ) {
	std::vector< int >	myVector;
	std::deque< int >	myDeque;
	std::list< int >	myList;

	int					a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int					f;
	
	f = 0;
	for ( int i = 0; i < 10; i++ ) {
		myVector.push_back( a[ i ] );
		myDeque.push_back( a[ i ] );
		myList.push_back( a[ i ] );
	}
	test( myVector, f );	
	test( myDeque, f );
	test( myList, f );
	return 0;
}
