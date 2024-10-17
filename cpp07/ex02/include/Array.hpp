/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:41:10 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/17 18:05:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< class T >
class Array {
	private:
		unsigned int	_size;
		T				*_array;
	public:
		Array( void );
		Array( unsigned int	n );
		Array( const Array& old );
		~Array( void );
		Array&	operator=( const Array& old );
		unsigned int	size( void ) const;
		T&		operator[]( unsigned int n );
		T&		operator[]( const unsigned int n ) const ;
};

template< class T >
std::ostream &operator<<( std::ostream& os, const Array< T >& obj );

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
	this->_size = old.size();
	this->_array = new T[ this->_size ]();
	if ( this->_size != 0 ) {
		for ( unsigned int i = 0; i < this->_size ; i++ ) {
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
	this->_size = old.size();
	if ( this->_array )
		delete[] this->_array;
	if ( this->_size ) {
		this->_array = new T[ this->_size ]();
		for ( unsigned int i = 0; i < this->_size ; i++ ) {
			this->_array[i] = old._array[i];
		}
	}
	return *this;
}

template< class T >
unsigned int Array< T >::size( void ) const {
	return this->_size;
}

template< typename T >
T&			Array< T >::operator[]( unsigned int n ) {
	if ( !this->_array )
		throw std::logic_error( "Trying to access an empty array\n" );
	else if ( this->_size >= n )
		throw std::out_of_range( "Index is out of range\n" );
	return ( this->_array[ n ] );
}

template< typename T >
T&	Array< T >::operator[]( unsigned int n ) const {
	if ( !this->_array )
		throw std::logic_error( "Trying to access an empty array\n" );
	else if ( n >= this->_size )
		throw std::out_of_range( "Index is out of range\n" );
	return ( this->_array[ n ] );
}
