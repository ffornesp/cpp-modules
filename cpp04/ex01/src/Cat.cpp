/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:43:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 10:37:46 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}
Cat::Cat( std::string name ) {
	std::cout << "Cat string constructor called" << std::endl;
	this->_type = name;
	this->_brain = new Brain();
}
Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}
Cat::Cat( const Cat& old ) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = old;
}
Cat&	Cat::operator=( const Cat& old ) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
		*this->_brain = *old._brain;
	}
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "Nyaa nyaa" << std::endl;
}
