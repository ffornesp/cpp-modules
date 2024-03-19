/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:43:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/18 17:33:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	this->_sound = "nyaa";
}
WrongCat::WrongCat( std::string name ) {
	std::cout << "WrongCat string constructor called" << std::endl;
	this->_type = name;
	this->_sound = "nyaa";
}
WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat::WrongCat( const WrongCat& old ) : Animal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = old;
}
WrongCat&	WrongCat::operator=( const WrongCat& old ) {
	std::cout << "WrongCat copy assignment operator" << std::endl;
	if (this != &old) {
		this->_type = old._type;
	}
	return (*this);
}
