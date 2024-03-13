/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:25 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 11:27:00 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	
}

Weapon::~Weapon( void ) {

}

const std::string&	Weapon::getType( void ) {
	return this->_type;
}

bool	Weapon::setType( std::string type ) {
	this->_type = type;
	return true;
}