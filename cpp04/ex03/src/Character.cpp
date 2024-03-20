/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 17:10:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {
	this->_name = "Default_character";
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
	this->_amount = 0;
}
Character::Character( std::string name ) : _name(name) {
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
	this->_amount = 0;
}
Character::~Character( void ) {

}
Character::Character( const Character& old ) {
	*this = old;
}
Character& Character::operator=( const Character& old ) {
	if (this != &old) {
		this->_name = old._name;
		for ( int i = 0; i < 4; i++ )
			this->_inventory[i] = old._inventory[i];
		this->_amount = old._amount;
	}
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
