/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:27 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 14:15:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) : _weapon("") {
	this->_name = name;
}

HumanB::~HumanB() {
	
}

void	HumanB::attack () {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
	std::cout << std::endl;
}

bool	HumanB::setWeapon( Weapon weapon ) {
	this->_weapon = weapon;
	return true;
}