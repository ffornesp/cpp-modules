/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:58:04 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 18:30:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ) : _type("default_type") {
	std::cout << "AAnimal default constructor called" << std::endl;
}
AAnimal::AAnimal( std::string name ) : _type(name) {
	std::cout << "AAnimal string constructor called" << std::endl;
}
AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called" << std::endl;
}
AAnimal::AAnimal( const AAnimal& old ) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = old;
}
AAnimal&	AAnimal::operator=( const AAnimal& old ) {
	std::cout << "AAnimal copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

void	AAnimal::makeSound( void ) const {
	std::cout << _type << " noises" << std::endl;
}
std::string	AAnimal::getType( void ) const { 
	return (this->_type);
}
