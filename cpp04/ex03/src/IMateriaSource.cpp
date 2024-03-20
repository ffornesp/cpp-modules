/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/20 17:04:04 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void ) : _type("NULL"), _amount(0) {
	
}
IMateriaSource::~IMateriaSource( void ) {

}
IMateriaSource::IMateriaSource( const IMateriaSource& old ) {
	*this = old;
}
IMateriaSource& IMateriaSource::operator=( const IMateriaSource& old ) {
	if (this != &old) {
		this->_type = old._type;
		for ( int i = 0; i < 4; i++ )
			this->_mats[i] = old._mats[i];
		this->_amount = old._amount;
	}
	return (*this);
}
