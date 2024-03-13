/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:38 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 16:21:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

const int	Fixed::_int8 = 8;

Fixed::Fixed( ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _value(n << _int8) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _value(f * (1 << _int8)) {
	std::cout << "Float constructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	//os << std::setprecision(5) << fixed.toFloat();
	return (os);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (this->_value / (float)(1 << _int8));
}

int	Fixed::toInt( void ) const {
	return(this->_value >> _int8);
}