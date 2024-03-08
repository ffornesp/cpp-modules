/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:41:38 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/08 12:46:08 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include <iostream>

Zombie::Zombie( void ) {
	
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << ": was destroyed" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

bool	Zombie::setName( std::string name ) {
	this->_name = name;
	return true;
}