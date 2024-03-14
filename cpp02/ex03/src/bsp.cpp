/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:21:02 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/14 11:22:27 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static Point	vector2(Point p1, Point p2) {
	Fixed	x((p2.getX() - p1.getX()));
	Fixed	y((p2.getY() - p1.getY()));
	Point	v(x.toFloat(), y.toFloat());
	// std::cout << v.getX() << " | " << v.getY() << std::endl;
	return (v);
}

static float	crossProduct( Point p1, Point p2 ) {
	Point	r;
	
	return (((p1.getX() * p2.getY()) - (p1.getY() * p2.getX())).toFloat());
}

static bool	pointCheck( Point p, Point a, Point b, Point c ) {
	if (p == a || p == b || p == c)
		return true;
	else if (a == b || a == c || b == c)
		return true;
	return false;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
    Fixed	ap_x = point.getX() - a.getX();
    Fixed	ap_y = point.getY() - a.getY();
	Point	vp[3] = { vector2(point, a), vector2(point, b), vector2(point, c) };
	Fixed	r[3];
	
	if (pointCheck(point, a, b, c))
		return false;
	r[0] = crossProduct(vp[0], vp[1]);
	r[1] = crossProduct(vp[1], vp[2]);
	r[2] = crossProduct(vp[2], vp[0]);
	// std::cout << "v1: " << vp[0].getX() << " | " << vp[0].getY() << std::endl;
	// std::cout << "v2: " << vp[1].getX() << " | " << vp[1].getY() << std::endl;
	// std::cout << "v3: " << vp[2].getX() << " | " << vp[2].getY() << std::endl;
	// std::cout << "r1: " << r[0] << std::endl;
	// std::cout << "r2: " << r[1] << std::endl;
	// std::cout << "r3: " << r[2] << std::endl;
	return ((r[0] > 0 && r[1] > 0 && r[2] > 0) || (r[0] < 0 && r[1] < 0 && r[2] < 0));
}