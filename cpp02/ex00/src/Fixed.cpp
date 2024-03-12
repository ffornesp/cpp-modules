/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:38 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 11:27:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( ) {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
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
