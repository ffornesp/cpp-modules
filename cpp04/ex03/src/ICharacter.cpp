/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 11:54:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {
	
}
ICharacter::ICharacter( std::string const & type ) {

}
ICharacter::~ICharacter( void ) {

}
ICharacter::ICharacter( const ICharacter& old ) {
	*this = old;
}
ICharacter& ICharacter::operator=( const ICharacter& old ) {
	return (*this);
}
