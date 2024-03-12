/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:41:44 by ffornes-          #+#    #+#             */
/*   Updated: 2024/03/12 10:55:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int					_value;
		static const int	_int8 = 8;
	public:
		Fixed( );
		~Fixed( );
		Fixed(const Fixed& oldfix);
		Fixed&	operator=(const Fixed& oldfix);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif