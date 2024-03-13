/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:38 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 17:44:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

const int	Fixed::_int8 = 8;

Fixed::Fixed( ) : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _value(n << _int8) {
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _value(f * (1 << _int8)) {
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& oldfix) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = oldfix;
}

int		Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (this->_value / (float)(1 << _int8));
}

int	Fixed::toInt( void ) const {
	return(this->_value >> _int8);
}

Fixed& Fixed::operator=(const Fixed& oldfix) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &oldfix)
		this->_value = oldfix.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& fix) {
	return (_value > fix._value);
}
bool	Fixed::operator<(const Fixed& fix) {
	return (_value < fix._value);
}

bool	Fixed::operator>=(const Fixed& fix) {
	return (_value >= fix._value);
}
bool	Fixed::operator<=(const Fixed& fix) {
	return (_value <= fix._value);
}
		
bool	Fixed::operator==(const Fixed& fix) {
	if (_value == fix._value)
		return true;
	return false;
}
bool	Fixed::operator!=(const Fixed& fix) {
	if (_value != fix._value)
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed& fix) {
	return (this->toFloat() + fix.toFloat());
}
Fixed	Fixed::operator-(const Fixed& fix) {
	return (this->toFloat() - fix.toFloat());
}

Fixed	Fixed::operator*(const Fixed& fix) {
	return (this->toFloat() * fix.toFloat());
}
Fixed	Fixed::operator/(const Fixed& fix) {
	return (this->toFloat() / fix.toFloat());
}

Fixed&	Fixed::operator++( void ) {
	++this->_value;
	return (*this);
}
Fixed	Fixed::operator++( int ) {
	Fixed	aux(*this);
	
	++this->_value;
	return (aux);
}

Fixed&	Fixed::operator--( void ) {
	--this->_value;
	return (*this);
}
Fixed	Fixed::operator--( int ) {
	Fixed	aux(*this);

	--(*this);
	return (aux);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}
Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	if ((Fixed)f1 < f2)
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}
Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
		if ((Fixed)f1 > f2)
		return ((Fixed&)f1);
	return ((Fixed&)f2);
}