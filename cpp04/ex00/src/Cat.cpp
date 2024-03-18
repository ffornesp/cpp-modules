/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:43:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 17:33:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}
Cat::Cat( std::string name ) {
	std::cout << "Cat string constructor called" << std::endl;
	this->_type = name;
}
Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}
Cat::Cat( const Cat& old ) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = old;
}
Cat&	Cat::operator=( const Cat& old ) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}


void	Cat::makeSound( void ) const {
	std::cout << "nyaa" << std::endl;
}
std::string	Cat::getType( void ) const { 
	return (this->_type);
}
