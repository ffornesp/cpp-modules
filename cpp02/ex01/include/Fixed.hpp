/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:44 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/13 12:08:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_int8;
	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float f );
		~Fixed( void );
		Fixed(const Fixed& oldfix);
		Fixed&	operator=(const Fixed& oldfix);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif