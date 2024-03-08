/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:34 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 14:14:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon *weapon ) {
	this->_name = name;
	this->_weapon = weapon;
}

HumanA::~HumanA() {
	
}

void	HumanA::attack () {
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType();
	std::cout << std::endl;
}