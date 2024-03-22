/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/22 11:42:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

void	Character::deleteInventory( void ) {
	for ( int i = 0; i < 4; i++ ) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

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
	deleteInventory();
}
Character::Character( const Character& old ) : ICharacter() {
	*this = old;
}
Character& Character::operator=( const Character& old ) {
	if (this != &old) {
		this->_name = old._name;
		this->_amount = old._amount;
		deleteInventory();
		for ( int i = 0; i < 4; i++ )
			if (old._inventory[i])
				this->_inventory[i] = old._inventory[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName( void ) const {
	return (this->_name);
}

void	Character::equip( AMateria *m ) {
	if (!m)
		std::cerr << "Materia recieved is NULL\n";
	else if (this->_amount >= 4) {
		std::cerr << "Unable to equip new materia since inventory is full" << std::endl;
		return ;
	}
	else {
		for ( int i = 0; i < 4; i++ ) {
			if (this->_inventory[i] == m) {
				std::cerr << this->_name << " already has this materia\n";
				return ;
			}
		}
		for ( int i = 0; i < 4; i++ ) {
			if (!this->_inventory[i]) {
				std::cout << "Equipped new materia in slot " << i << std::endl;
				this->_inventory[i] = m;
				this->_amount++;
				return ;
			}
		}
	}
	std::cout << "Unable to equip new materia since slot is full\n";
}
void	Character::unequip( int idx ) {
	if (idx < 0 || idx > 3) {
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	else if (!this->_inventory[idx]) {
		std::cerr << "There's no materias in this inventory slot" << std::endl;
	}
	else {
		std::cout << "Unequipped materia in slot " << idx << std::endl;
		this->_inventory[idx] = NULL;
		this->_amount--;
	}
}
void	Character::use( int idx, ICharacter& target ) {
	if (idx < 0 || idx > 3)
		std::cerr << "Index out of range" << std::endl;
	else if (!this->_inventory[idx])
		std::cerr << "There's no materia in index " << idx << std::endl;
	else if (this->_inventory[idx]->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	else if (this->_inventory[idx]->getType() == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
