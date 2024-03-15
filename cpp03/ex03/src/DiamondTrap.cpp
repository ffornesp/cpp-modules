/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:59:31 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 14:50:07 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "DiamondTrap_default";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hP = FragTrap::_hP;
	this->_energy = ScavTrap::_energy;
	this->_atk = FragTrap::_atk;
}
DiamondTrap::DiamondTrap( std::string name ) {
	std::cout << "DiamondTrap string constructor called" << std::endl;
	_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hP = FragTrap::_hP;
	this->_energy = ScavTrap::_energy;
	this->_atk = FragTrap::_atk;
}
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap default destructor called" << std::endl;
}
DiamondTrap::DiamondTrap( const DiamondTrap& old ) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = old;
}
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& old ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &old) {
		this->_name = old._name;
		this->_hP = old.::FragTrap::_hP;
		this->_energy = old.::ScavTrap::_energy;
		this->_atk = old.::FragTrap::_atk;
	}
	return (*this);
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "Diamond name: [" << this->_name << "] Clap name: [" \
	<< this->ClapTrap::_name << "]" << std::endl;
}