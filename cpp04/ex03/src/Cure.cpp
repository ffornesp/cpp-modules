/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/21 17:34:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure( void ) {
	this->AMateria::_type = "cure";	
}
Cure::~Cure( void ) {

}
Cure::Cure( const Cure& old ) : AMateria() {
	*this = old;
}
Cure& Cure::operator=( const Cure& old ) {
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

AMateria*	Cure::clone( void ) const {
	return (new Cure());
}

void	Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" \
	<<  std::endl;
}
