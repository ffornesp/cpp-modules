/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:38 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 16:39:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) {

}

Fixed::Fixed( const float f ) {

}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& oldfix) {
	std::cout << "Copy constructor called" << std::endl;
	*this = oldfix;
}

Fixed& Fixed::operator=(const Fixed& oldfix) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &oldfix)
		this->_value = oldfix.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	toFloat( void ) const {

}

int		toInt( void ) const {

}