/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:31:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 12:56:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrapDefs.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "ScavTrap_default";
	this->_hP = 100;
	this->_energy = 50;
	this->_atk = 20;
}
ScavTrap::ScavTrap( std::string name ) {
	std::cout << "ScavTrap string constructor called" << std::endl;
	this->_name = name;
	this->_hP = 100;
	this->_energy = 50;
	this->_atk = 20;
}
ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap default destructor called" << std::endl;
}
ScavTrap::ScavTrap( const ScavTrap& old ) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = old;
}
ScavTrap&	ScavTrap::operator=(const ScavTrap& old ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &old) {
		this->_name = old._name;
		this->_hP = old._hP;
		this->_energy = old._energy;
		this->_atk = old._atk;
	}
	return (*this);
}

void	ScavTrap::guardGate( void ) {
	if (this->_hP > 0) {
		std::cout << YELLOW << this->_name << WHITE \
	<< " is now in Gate Keeper mode" << std::endl;
	}
	else
		std::cout << YELLOW << this->_name << WHITE \
		<< " can't be in Gate Keeper mode because " << RED \
		<< "it's dead" << WHITE << std::endl;
}
