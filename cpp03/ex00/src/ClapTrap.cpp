/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/14 15:24:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) : _name(""), _hP(10), _energy(10) {
	std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap( std::string name ) : _name(name), _hP(10), _energy(10) {
	std::cout << "String constructor called" << std::endl;
}
ClapTrap::~ClapTrap( void ) {
	std::cout << "Default destructor called" << std::endl;
}
void	ClapTrap::attack(const std::string& name) {
	if (this->_hP > 0 && this->_energy > 0) {
		this->_energy -= 1;
		std::cout << YELLOW << this->_name << WHITE << " attacks " << YELLOW << name << WHITE << std::endl;
	}
	else if (this->_hP <= 0)
		std::cout << YELLOW << this->_name << WHITE << " can't attack because " << RED \
		<< "it has no hit points left" << WHITE << std::endl;
	else
		std::cout << YELLOW << this->_name << WHITE << " can't attack because " << RED \
		<< "it has no energy left" << WHITE << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hP > 0) {
		this->_hP -= amount;
		std::cout << YELLOW << this->_name << WHITE" takes " << amount << " damage" << std::endl;
		if (this->_hP <= 0) {
			this->_hP = 0;
			std::cout << YELLOW << this->_name << WHITE" has no more hit points left! " << YELLOW \
			<< this->_name << RED << " has died!" << WHITE << std::endl;
		}
	}
	else
		std::cout << YELLOW << this->_name << WHITE << " can't take damage because " << RED << "it's dead" \
		<< WHITE << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hP > 0 && this->_energy > 0) {
		this->_energy -= 1;
		this->_hP += amount;
		if (this->_hP > 10)
			this->_hP = 10;
		std::cout << YELLOW << this->_name << WHITE" restored " << amount << " hit points" << std::endl;
	}
	else if (this->_hP <= 0)
		std::cout << YELLOW << this->_name << WHITE << " can't repair itself because " \
		<< RED << "it's dead" << WHITE <<  std::endl;
	else
		std::cout << YELLOW << this->_name << WHITE << " can't repair itself because " << RED \
		<< "it has no energy left\n" << WHITE;
}