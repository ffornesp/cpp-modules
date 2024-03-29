/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:40:06 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 15:14:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrapDefs.hpp"
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "FragTrap_default";
	this->_hP = 100;
	this->_energy = 100;
	this->_atk = 30;
}
FragTrap::FragTrap( std::string name ) {
	std::cout << "FragTrap string constructor called" << std::endl;
	this->_name = name;
	this->_hP = 100;
	this->_energy = 100;
	this->_atk = 30;
}
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap default destructor called" << std::endl;
}
FragTrap::FragTrap( const FragTrap& old ) : ClapTrap() {
	std::cout << "Default copy constructor called" << std::endl;
	*this = old;
}
FragTrap&	FragTrap::operator=(const FragTrap& old ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &old) {
		this->_name = old._name;
		this->_hP = old._hP;
		this->_energy = old._energy;
		this->_atk = old._atk;
	}
	return (*this);
}

void FragTrap::highFivesGuys( void ) {
	if (this->_hP > 0) {
		std::cout << "High fives!" << std::endl;
	}
	else
		std::cout << "Can't ask for high fives because " << RED \
		<< "it's dead" << WHITE << std::endl;
}
