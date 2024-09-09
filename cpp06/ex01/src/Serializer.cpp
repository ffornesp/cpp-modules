/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/09/09 13:23:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( const Serializer& copy )
{
	( void )copy;
}

Serializer&	Serializer::operator=( const Serializer& copy )
{
	( void )copy;
	return ( *this );
}

uintptr_t	Serializer::serialize( Data* ptr ) {
	uintptr_t	u;

	u = ( uintptr_t )( void* )ptr;
	return u;
}

Data*		Serializer::deserialize( uintptr_t raw ) {
	Data	*data;
	data = static_cast< Data* >( ( void* )raw );
	return ( data );
}
