/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:30:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/09/09 12:55:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

typedef struct	s_Data 
{
	int			i;
}				Data;

class	Serializer {
	private :
		Serializer( void );
		~Serializer( void );
		Serializer( const Serializer& copy );
		Serializer&	operator=( const Serializer& copy );
	public :
		static uintptr_t	serialize( Data* ptr ) ;
		static Data*		deserialize( uintptr_t raw ) ;
};
