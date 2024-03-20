/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:34:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( void ) : _type("default") {
	
}
ICharacter::ICharacter( std::string const & type ) : _type(type) {

}
ICharacter::~ICharacter( void ) {

}
ICharacter::ICharacter( const ICharacter& old ) {
	*this = old;
}
ICharacter& ICharacter::operator=( const ICharacter& old ) {
//	if (this != &old) {
//		this->_type = old._type;
//	}
	return (*this);
}
