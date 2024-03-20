/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 15:45:39 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _type("default"), _amount(0) {
	
}
MateriaSource::~MateriaSource( void ) {

}
MateriaSource::MateriaSource( const MateriaSource& old ) {
	*this = old;
}
MateriaSource& MateriaSource::operator=( const MateriaSource& old ) {
//	if (this != &old) {
//		this->_type = old._type;
//	}
	return (*this);
}

void	learnMateria( AMateria* mat ) {
	if (this->_amount >= 4) {
		std::cerr << "Materia Source can't learn more materia since it already" \
		<< " has learned 4 materias.
		return ;
	}
	else {
		for ( int i = 0; i < 4; i++ )
			if ( !this->_mats[i] )
				break ;
		this->_mats[i] = new Materia(*mat);
	}
}

AMateria *	MateriaSource::createMateria( std::string const & type ) {
	for ( int i = 0; i < 4; i++ )
		if ( mats[i]._type == type )
			return ( new AMateria(mats[i]));
	return 0;
}
