/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:35 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/14 11:15:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point( void );
		Point( const float x, const float y);
		~Point( void );
		Point( const Point& oldpoint );
		Point&	operator=(const Point& oldpoint);
		bool	operator==(const Point& oldpoint);
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

std::ostream&	operator<<( std::ostream& out, Point& p );
bool	bsp( Point const a, Point const b, Point const c, Point const point);