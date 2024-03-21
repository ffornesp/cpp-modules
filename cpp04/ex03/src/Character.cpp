/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/21 17:24:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character( void ) {
	this->_name = "Default_character";
	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = NULL;
	this->_amount = 0;
}
Character::Character( std::string name ) {
	this->_name = name;
	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = NULL;
	this->_amount = 0;
}
Character::~Character( void ) {

}
Character::Character( const Character& old ) : ICharacter() {
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

std::string const &	Character::getName( void ) const {
	return (this->_name);
}

void	Character::equip( AMateria *m ) {
	if (this->_amount >= 4) {
		std::cout << "Unable to equip new materia since inventory is full" << std::endl;
		return ;
	}
	else {
		for ( int i = 0; i < 4; i++ ) {
			if (!this->_inventory[i]) {
				std::cout << "Equipped new materia in slot " << i << std::endl;
				this->_inventory[i] = m;
				return ;
			}
		}
	}
}
void	Character::unequip( int idx ) {
	if (idx < 1 || idx > 4) {
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	else if (!this->_inventory[idx]) {
		std::cerr << "There's no materias in this inventory slot" << std::endl;
	}
	else {
		std::cout << "Unequipped materia in slot " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
}
void	Character::use( int idx, ICharacter& target ) {
	if (idx < 1 || idx > 4)
		std::cerr << "Index out of range" << std::endl;
	else if (!this->_inventory[idx])
		std::cerr << "There's no materia in index " << idx << std::endl;
	else if (this->_inventory[idx]->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	else if (this->_inventory[idx]->getType() == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
