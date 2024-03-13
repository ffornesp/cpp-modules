/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:34 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 19:48:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

// Found in https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

Fixed	calcArea(const Point p0, const Point p1, const Point p2) {
	Fixed	a;
	Fixed	b;
	Fixed	c;
	Fixed	d;

	a = (p1.getY() * -1) * p2.getX();
	b = p0.getY() * (p1.getX() * -1) + p2.getX();
	c = p0.getX() * (p1.getY() - p2.getY());
	d = p1.getX() * p2.getY();
	return ((Fixed)0.5f * ( a + b + c + d ));
}

Fixed	calcS(const Point p, const Point p0, const Point p1, const Point p2, Fixed area) {
	Fixed	a;
	Fixed	b;
	Fixed	c;

	a = p0.getY() * p2.getX() - p0.getX() * p2.getY();
	b = (p2.getY() - p0.getY()) * p.getX();
	c = (p0.getX() - p2.getX()) * p.getY();
	return ((Fixed)1 / (area * (Fixed)2) * (a + b + c));
}

Fixed	calcT(const Point p, const Point p0, const Point p1, const Point p2, Fixed area) {
	Fixed	a;
	Fixed	b;
	Fixed	c;

	a = p0.getX() * p1.getY() - p0.getY() * p1.getX();
	b = (p0.getY() - p1.getY()) * p.getX();
	c = (p1.getX() - p0.getX()) * p.getY();
	return ((Fixed)1 / (area * (Fixed)2) * (a + b + c));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	s;
	Fixed	t;
	Fixed	area;

	area = calcArea(a, b, c);
	s = calcS(point, a, b, c, area);
	t = calcT(point, a, b, c, area);
	if ((s >= 0 && s <= 1) && (t >= 0 & t <= 1) && ((s + t) <= 1))
		return true;
	return false;
}

int main( void ) {


}