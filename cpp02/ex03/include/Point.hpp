/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:35 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 19:08:23 by ffornes-         ###   ########.fr       */
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

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

bool	bdsp( Point const a, Point const b, Point const c, Point const point);