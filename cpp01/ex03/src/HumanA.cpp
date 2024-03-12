/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:34 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:06:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon) {
	this->_name = name;
}

HumanA::~HumanA() {
	
}

void	HumanA::attack () {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
	std::cout << std::endl;
}
