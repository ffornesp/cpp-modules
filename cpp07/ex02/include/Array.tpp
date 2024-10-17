/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:41:10 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/17 12:57:00 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template< typename T >
Array< T >::Array( void ) {
	this->_size = 0;
	this->_array = NULL;
}

template< typename T >
Array< T >::Array( unsigned int n ) {
	this->_size = n;
	this->_array = new T[ n ]();
}

template< typename T >
Array< T >::Array( const Array< T >& old ) {
	this->_size = old.size;
	this->_array = new T[ this->_size ]();
	if ( this->_size != 0 ) {
		for ( int i = 0; i < this->_size ; i++ ) {
			this->_array[i] = old._array[i];
		}
	}
}

template< typename T >
Array< T >::~Array( void ) {
	if ( this->_size )
		delete[] this->_array;
}

template< typename T >
Array< T >&	Array< T >::operator=( const Array< T >& old ) {
	this->_size = old.size;
	if ( this->_array )
		delete[] this->_array;
	if ( this->_size ) {
		this->_array = new T[ this->_size ]();
		for ( int i = 0; i < this->_size ; i++ ) {
			this->_array[i] = old._array[i];
		}
	}
	return *this;
}

template< typename T >
unsigned int::size( void ) const {
	return this->_size;
}

template< typename T >
T& Array< T >::operator[]( unsigned int n ) {

}

template< typename T >
T& Array< T >::operator[]( const unsigned int n ) const {
		
}
