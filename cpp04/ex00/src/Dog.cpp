/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:36:34 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/19 09:40:22 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}
Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}
Dog::Dog( const Dog& old ) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = old;
}
Dog&	Dog::operator=( const Dog& old ) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "Woof woof" << std::endl;
}
