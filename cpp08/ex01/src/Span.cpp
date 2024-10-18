/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:49:48 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/18 18:47:00 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <set>
#include <limits>
#include <cmath>
#include <algorithm>

Span::Span( void ) : _size( 0 ) {}

Span::Span( unsigned int size ) : _size(size) {}

Span::~Span( void ) {}

Span::Span( const Span& s ) {
	*this = s;
}

Span&	Span::operator=( const Span& copy ) {
	this->_size = copy._size;
	this->_content = copy._content;
	
	return *this;
}

void	Span::addNumber( int n ) {
	if ( this->_content.size() == this->_size ) {
		throw std::runtime_error( "Content is at max capacity, unable to add more numbers\n" );
	}
	this->_content.insert( n );
}

unsigned long	Span::shortestSpan( void ) {
	if ( this->_content.size() < 2 )
		throw std::runtime_error( "Unable to find shortest span\n" );

	long	n;
	long	span = std::numeric_limits< long >::max();
	for ( std::multiset< int >::iterator it = this->_content.begin(); it != this->_content.end() ; it++ ) {
		if ( it != this->_content.begin() && std::abs( *it - n ) < span )
			span = std::abs( *it - n );
		n = *it;
	}
	return span;
}

unsigned long	Span::longestSpan( void ) {
	if ( this->_content.size() < 2 )
		throw std::runtime_error( "Unable to find longest span\n" );

	long	span;
	std::multiset< int >::iterator	min;
	std::multiset< int >::iterator	max;
	min = std::min_element( this->_content.begin(), this->_content.end() );
	max = std::max_element( this->_content.begin(), this->_content.end() );
	span = std::abs( static_cast< long >( *max ) - static_cast< long >( *min ));
	return span;
}
