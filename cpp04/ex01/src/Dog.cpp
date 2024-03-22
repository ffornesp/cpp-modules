/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:36:34 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 10:42:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}
Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}
Dog::Dog( const Dog& old ) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = old;
}
Dog&	Dog::operator=( const Dog& old ) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
		*this->_brain = *old._brain;
	}
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "Woof woof" << std::endl;
}
