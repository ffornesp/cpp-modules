/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:49:48 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 19:06:20 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <stdexcept>

class Span {
	private:
		unsigned int 			_size;
		std::multiset< int >	_content;
	public:
		Span( void );
		Span( unsigned int size );
		~Span( void );
		Span( const Span& s );
		Span&	operator=( const Span& copy );

		void	addNumber( int n );
		template< typename T >
		void	addNumbers( T& t );
		unsigned long	shortestSpan( void );
		unsigned long	longestSpan( void );
};

template< typename T >
void	Span::addNumbers( T& t ) {
	typename T::iterator it = t.begin();
	typename T::iterator ite = t.end();
	if ( std::distance( it, ite ) + this->_content.size() > this->_size )
		throw std::runtime_error( "Content is unable to handle this amount of elements\n" );
	this->_content.insert( it, ite );
}
