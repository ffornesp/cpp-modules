/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:31:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/15 11:04:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "{PUTATOAUTOPAISJA";
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap default destructor called" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	
}
