/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:49:48 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 20:31:12 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template< typename T >
class MutantStack : public std::stack< T > {
	public:
		MutantStack( void );
		~MutantStack( void );
		MutantStack( const MutantStack& m );
		MutantStack&	operator=( const MutantStack& copy );

		typedef typename std::stack< T >::container_type::iterator iterator;
		iterator	begin( void );
		iterator	end( void );
};

template< typename T >
MutantStack< T >::MutantStack( void ): std::stack< T >( ) {}

template< typename T >
MutantStack< T >::~MutantStack( void ) {}

template< typename T >
MutantStack< T >::MutantStack( const MutantStack& m ) : std::stack< T >( m ) {}

template< typename T >
MutantStack< T >&	MutantStack< T >::operator=( const MutantStack& copy ) {
	return ( std::stack< T >::operator=( copy ) );
}

template< typename T >
typename MutantStack< T >::iterator	MutantStack< T >::begin( void ) {
	return this->c.begin();
}

template< typename T >
typename MutantStack< T >::iterator MutantStack< T >::end( void ) {
	return this->c.end();
}
