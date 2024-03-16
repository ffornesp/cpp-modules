/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:33:08 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 15:36:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrapDefs.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) : _name("default_name"), _hP(10), _energy(10), _atk(0) {
	std::cout << "Default constructor called" << std::endl;
	this->_initHp = this->_hP;
}
ClapTrap::ClapTrap( std::string name ) : _name(name), _hP(10), _energy(10), _atk(0) {
	std::cout << "String constructor called" << std::endl;
	this->_initHp = this->_hP;
}
ClapTrap::~ClapTrap( void ) {
	std::cout << "Default destructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=( const ClapTrap& old ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &old) {
		this->_name = old._name;
		this->_hP = old._hP;
		this->_energy = old._energy;
		this->_atk = old._atk;
		this->_initHp = old._initHp;
	}
	return (*this);
}
ClapTrap::ClapTrap( const ClapTrap& old ) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = old;
}

void	ClapTrap::attack(const std::string& name) {
	if (this->_hP > 0 && this->_energy > 0) {
		this->_energy -= 1;
		std::cout << YELLOW << this->_name << WHITE << " attacks " << YELLOW << name << WHITE \
		<< " with " << this->_atk << " attack damage" << std::endl;
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
		std::cout << YELLOW << this->_name << WHITE << " takes " << RED << amount << WHITE \
		<< " damage. ";
		if (amount > this->_hP)
			amount = this->_hP;
		this->_hP -= amount;
		if (this->_hP == 0) {
			std::cout << YELLOW << this->_name << WHITE << " has no more hit points left! " << YELLOW \
			<< this->_name << RED << " has died!" << WHITE << std::endl;
		}
		else {
			std::cout << YELLOW << this->_name << WHITE << " has " << this->_hP << " hit points left!" << std::endl;
		}
	}
	else
		std::cout << YELLOW << this->_name << WHITE << " can't take damage because " << RED << "it's dead" \
		<< WHITE << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hP > 0 && this->_energy > 0) {
		if (this->_hP == this->_initHp) {
			std::cout << YELLOW << this->_name << WHITE << " can't repair itself because" \
			<< " it's hit points are full!" << std::endl;
			return ;
		}
		this->_energy -= 1;
		if ((this->_hP + amount) > this->_initHp)
			amount -= this->_hP + amount - this->_initHp;
		this->_hP += amount;
		std::cout << YELLOW << this->_name << WHITE" restored " << GREEN << amount << WHITE \
		<< " hit points" << std::endl;
	}
	else if (this->_hP == 0)
		std::cout << YELLOW << this->_name << WHITE << " can't repair itself because " \
		<< RED << "it's dead" << WHITE <<  std::endl;
	else
		std::cout << YELLOW << this->_name << WHITE << " can't repair itself because " << RED \
		<< "it has no energy left\n" << WHITE;
}
