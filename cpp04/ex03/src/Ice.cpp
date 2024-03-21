/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/21 17:35:44 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice( void ) {
	this->AMateria::_type = "ice";	
}
Ice::~Ice( void ) {

}
Ice::Ice( const Ice& old ) : AMateria() {
	*this = old;
}
Ice& Ice::operator=( const Ice& old ) {
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

AMateria*	Ice::clone( void ) const {
	return (new Ice());
}

void	Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() \
	<< " *" <<  std::endl;
}
