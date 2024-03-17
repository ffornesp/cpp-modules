/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:40:06 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 12:49:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "FragTrap_default";
	this->_hP = 100;
	this->_energy = 100;
	this->_atk = 30;
	this->_initHp = this->_hP;
}
FragTrap::FragTrap( std::string name ) {
	std::cout << "FragTrap string constructor called" << std::endl;
	this->_name = name;
	this->_hP = 100;
	this->_energy = 100;
	this->_atk = 30;
	this->_initHp = this->_hP;
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
		this->_initHp = old._hP;
	}
	return (*this);
}

void FragTrap::highFivesGuys( void ) { 
	std::cout << "High fives!" << std::endl;
}
