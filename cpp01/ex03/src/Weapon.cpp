/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:25 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:06:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	setType(type);
}

Weapon::~Weapon( ) {

}

std::string const	Weapon::getType() {
	return this->_type;
}

bool	Weapon::setType( std::string type ) {
	this->_type = type;
	return true;
}