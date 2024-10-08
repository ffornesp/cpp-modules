/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:00:45 by herz              #+#    #+#             */
/*   Updated: 2024/10/08 12:44:35 by ffornes-         ###   ########.fr       */
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

	u = reinterpret_cast< uintptr_t >( ptr );
	return u;
}

Data*		Serializer::deserialize( uintptr_t raw ) {
	Data	*data;
	
	data = reinterpret_cast< Data * >( raw );
	return ( data );
}
