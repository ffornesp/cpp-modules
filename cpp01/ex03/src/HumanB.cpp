/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:27 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/11 11:30:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) {
	this->_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {
	
}

void	HumanB::attack () {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType();
	else
		std::cout << this->_name << " attacks with their fists";
	std::cout << std::endl;
}

bool	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
	return true;
}
