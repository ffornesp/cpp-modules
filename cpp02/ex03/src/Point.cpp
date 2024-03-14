/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:23 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/14 11:15:22 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x(0), _y(0) {
}

Point::Point( const float x, const float y ) : _x(x), _y(y) {
	
}

Point::~Point( void ) {
}

Point::Point( const Point& oldpoint ) : _x(oldpoint._x), _y(oldpoint._y) {
}

Point& Point::operator=( const Point& oldpoint ) {
	if (this != &oldpoint) {
		std::cout << "Copy constructor called" << std::endl;
		(Fixed)this->_x = oldpoint._x;
		(Fixed)this->_y = oldpoint._y;
	}
	return (*this);
}

bool	Point::operator==(const Point& p) {
	if ( this->getX() == p._x && this->getY() == p._y )
		return true;
	return false;
}

Fixed	Point::getX( void ) const {
	return (this->_x);
}

Fixed	Point::getY( void ) const {
	return (this->_y);
}

std::ostream&	operator<<( std::ostream& out, Point& p )
{
	out << "x: " << p.getX() << ", y: " << p.getY();
	return ( out );
}