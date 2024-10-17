/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:41:10 by ffornes-          #+#    #+#             */
/*   Updated: 2024/10/17 13:12:16 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template< class T >
public Class Array {
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
} ;

#include "Array.tpp"
