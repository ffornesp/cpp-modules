/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 11:56:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("Default_name") {
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}
Character::Character( std::string const & type ) : _name(type) {
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}
Character::~Character( void ) {

}
Character::Character( const Character& old ) {
	*this = old;
}
Character& Character::operator=( const Character& old ) {
	return (*this);
}

std::string	Character::getName( void ) {
	return (this->_name);
}

void	Character::equip( AMateria *m ) {
	
}
void	Character::unequip( int idx ) {

}
void	Character::use( int idx, Character& target ) {

}
