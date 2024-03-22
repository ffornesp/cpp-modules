/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/22 10:53:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) : _type("default") {
	
}
AMateria::AMateria( std::string const type ) : _type(type) {

}
AMateria::~AMateria( void ) {

}
AMateria::AMateria( const AMateria& old ) {
	*this = old;
}
AMateria& AMateria::operator=( const AMateria& old ) {
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

std::string const & AMateria::getType( void ) const {
	return (this->_type);
}

void	AMateria::use( ICharacter& target ) {
	(void)target;
}
