/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:34:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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
