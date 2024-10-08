/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:59:40 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/08 16:21:34 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename T >
void	iter( T * a, unsigned int len, void ( * f )( T )) {
	if ( a != NULL )
		for ( unsigned int i = 0; i < len; i++ )
			f( a[ i ] );
}

template< typename T >
void	iter( const T * a, unsigned int len, void ( *f )( const T& )) {
	if ( a != NULL )
		for ( unsigned int i = 0; i < len; i++ )
			f( a[ i ] );
}

template< typename T >
void	print_content( T t ) {
	std::cout << t << std::endl;
}

template< typename T >
void	test1( T * t, unsigned int len ) {
	iter( t, len, print_content );
}
