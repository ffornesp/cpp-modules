/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:03:07 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 17:34:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

const std::string _sound = "Wrong animal noises";

WrongAnimal::WrongAnimal( void ) : _type("default_type") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal( std::string name ) : _type(name) {
	std::cout << "WrongAnimal string constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal::WrongAnimal( const WrongAnimal& old ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = old;
}
WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& old ) {
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

void	WrongAnimal::_makeSound( void ) const {
	std::cout << this->_sound << std::endl;
}
std::string	WrongAnimal::getType( void ) const { 
	return (this->_type);
}
