/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:58:04 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 09:40:08 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : _type("default_type") {
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal( std::string name ) : _type(name) {
	std::cout << "Animal string constructor called" << std::endl;
}
Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}
Animal::Animal( const Animal& old ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = old;
}
Animal&	Animal::operator=( const Animal& old ) {
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

void	Animal::makeSound( void ) const {
	std::cout << _type << " noises" << std::endl;
}
std::string	Animal::getType( void ) const { 
	return (this->_type);
}
