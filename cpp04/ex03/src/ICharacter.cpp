/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 17:02:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( void ) : _name("Default_name"), _amount(0) {

}
ICharacter::ICharacter( std::string name ) : _name(name), _amount(0) {

}
ICharacter::~ICharacter( void ) {

}
ICharacter::ICharacter( const ICharacter& old ) {
	*this = old;
}
ICharacter& ICharacter::operator=( const ICharacter& old ) {
	if ( this != &old ) {
		this->_name = old._name;
		for ( int i = 0; i < 4; i++ )
			this->_inventory[i] = old._inventory[i];
		this->_amount = old._amount;
	}
	return (*this);
}
