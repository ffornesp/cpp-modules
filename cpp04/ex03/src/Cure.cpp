/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:34:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : _type("default") {
	
}
Cure::Cure( std::string const & type ) : _type(type) {

}
Cure::~Cure( void ) {

}
Cure::Cure( const Cure& old ) {
	*this = old;
}
Cure& Cure::operator=( const Cure& old ) {
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}
