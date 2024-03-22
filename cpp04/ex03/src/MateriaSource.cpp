/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/22 11:41:44 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource( void ) : _type("default"), _amount(0) {
	for ( int i = 0; i < 4; i++ )
		this->_mats[i] = NULL;
}
MateriaSource::~MateriaSource( void ) {
	for ( int i = 0; i < 4; i++ )
		if (this->_mats[i])
			delete _mats[i];
}
MateriaSource::MateriaSource( const MateriaSource& old ) {
	*this = old;
}
MateriaSource& MateriaSource::operator=( const MateriaSource& old ) {
	if (this != &old) {
		this->_type = old._type;
		for ( int i = 0; i < 4; i++ )
			this->_mats[i] = old._mats[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* mat ) {
	if (this->_amount >= 4) {
		std::cerr << "Materia Source can't learn more materia since it already" \
		<< " has learned 4 materias.";
		delete mat;
		return ;
	}
	else {
		for ( int i = 0; i < 4; i++ ) {
			if ( !this->_mats[i] ) {
				this->_mats[i] = mat;
				this->_amount++;
				break ;
			}
		}
	}
}

AMateria *	MateriaSource::createMateria( std::string const & type ) {
	for ( int i = 0; i < 4; i++ )
		if ( this->_mats[i] && this->_mats[i]->getType() == type )
			return ( this->_mats[i]->clone() );
	std::cerr << "No materia matching type [" << type << "] was found" \
	<< std::endl;
	return 0;
}
