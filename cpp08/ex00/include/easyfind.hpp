/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:59:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 15:36:54 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>

template< typename T >
int		easyFind( T& t, int n ) {
	for ( typename T::iterator it = t.begin() ; it != t.end() ; ++it ) {
		if ( *it == n )
			return n;
	}
	throw std::runtime_error( "Unable to find " );
}

template< typename T >
void	test( T& t, int n ) {
	try {
		easyFind< T >( t, n );
		std::cout << "Found " << n << " in vector\n";
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << n << std::endl;
	}
}
