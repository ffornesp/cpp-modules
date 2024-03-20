/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 12:12:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void ) : _type("default") {
	
}
IMateriaSource::~IMateriaSource( void ) {

}
IMateriaSource::IMateriaSource( const IMateriaSource& old ) {
	*this = old;
}
IMateriaSource& IMateriaSource::operator=( const IMateriaSource& old ) {
//	if (this != &old) {
//		this->_type = old._type;
//	}
	return (*this);
}
