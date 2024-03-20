/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:34:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : _type("default") {
	
}
Ice::Ice( std::string const & type ) : _type(type) {

}
Ice::~Ice( void ) {

}
Ice::Ice( const Ice& old ) {
	*this = old;
}
Ice& Ice::operator=( const Ice& old ) {
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}
